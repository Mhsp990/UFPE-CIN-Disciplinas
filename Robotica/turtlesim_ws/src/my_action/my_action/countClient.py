import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from tutorial_interfaces.action import CountUntil
import time


class CountClient(Node):

    def __init__(self):
        super().__init__("count_client")

        #Criar o CLIENTE da ação
        self.client = ActionClient(
            self,
            CountUntil,
            "count_until",
            #Neste caso, contendo apenas os parametros acima, é um cliente minimo, sem feedback, etc. Parece o cliente de servidor.
            #Não tem feedback, reação a resultado, cancelado, reação a resposta do goal request, etc.
        )

        self.target = 5


    def send_goal(self):
        # Verificar e esperar o servidor da ação estar livre.
        self.client.wait_for_server()


        #Criando o goal e populando-o
        goal = CountUntil.Goal() #Apenas a parte goal, neste caso
        goal.target = self.target

        future = self.client.send_goal_async(goal)

        # print("Awaiting for goal to be accepted") #Isso daqui está esperando o goal ser ACEITO, pois future recebe a aceitação ou recusa do goal
        # rclpy.spin_until_future_complete(self, future)
        # print("Action goal has been accepted.")

        #Callback que será chamado quando houver resposta sobre o PEDIDO de action. Pode ser aceito ou negado
        future.add_done_callback(self.goal_response_callback) 

    def goal_response_callback(self, future):
        #Executado quando há uma resposta sobre o PEDIDO de iniciar a ação.
        goal_handle = future.result() #Resultado do pedido, não da action.

        if not goal_handle.accepted:
            self.get_logger().info("Goal was not accepted")
            rclpy.shutdown() #Mata o nó se for recusado. Neste exemplo, este node só existe para pedir essa ação uma vez.
            return
        
        self.get_logger().info(f'Goal was accepted!')

        #Como foi aceito, vamos pedir o resultado também. Ou seja, reagir ao resultado.
        future = goal_handle.get_result_async()
        future.add_done_callback(self.result_callback) #Chamado quando há um resultado, ou por terminar a action, cancelado, abortado, etc.
        #OBS : É possível cria rum feedback específico para quando é cancelado, etc.

    def result_callback(self, future):
        #Gatilhando quando a ação é finalizada, retornando o resultado. Pode ter sido por temrinar a ação, cancelada, abortada.
        pass



def main(args = None):
    rclpy.init(args=args)
    myCountClient = CountClient()
    myCountClient.send_goal()

    rclpy.spin(myCountClient)

    myCountClient.destroy_node()
    rclpy.shutdown()



if __name__ == "__main__":
    main()