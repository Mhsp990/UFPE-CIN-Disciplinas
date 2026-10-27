import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from tutorial_interfaces.interfaces.action import CountUntil
import time



class CountServerNode(Node):

    def __init__(self):
        super().__init__("count_until_server")

        #Criando o sevidor de ação. 4 argumentos no minimo.
        #Pode ter mais de um callback associado. POr isos, use o nome na hora de atribuir o parametro.
        #Neste caso, é um action minimo, contendo apensa o execute callback
        self.server = ActionServer(
            self,
            CountUntil, #Tipo
            "count_until", #Nome do action
            execute_callback= self.execute_count_until #Lembre de por este execute_callback = callable. Este é o callback de execute.
            #Um action mais completo PODERIA ter, por exmeplo, um callback para quando é cancelado, etc.
        )

    def execute_count_until(self, goal_handle):
        #Goal handle tem os seguintes campos:
        #goal_handle.request é a parte request, descrita no arquivo .action associado.
        #goal_handle.goal_id é Identificador unico
        #goal_handle.status  é o estado atual
        #goal_handle.is_cancel_requested informa se o processo de cancelar o request foi iniciado (ou terminado).

        #goal_handle.succeed() é usado para COMPLETAR com sucesso a execução.
        #goal_handle.abort() completa com FALHA a execução.
        #goal_handle.cancel()

        #O retorno da função será do "tipo" CountUntil.RESULT, que irá conter, dentro dele, as informações necessárias.

        #Leia o request
        target = goal_handle.request.target #Campo target, descrito no arquivo .action (custom)
        simulate_failure = goal_handle.request.simulate_failure

        #Crie a variavel que será o retorno
        result = CountUntil.Result()
        result.reached = 0

        #Execute a "ação"
        while result.reached < target:
            time.sleep(0.5) #Simulando um processamento.
            result.reached += 1

        #Para finalizar a ação, deve-se setar (conforme o contexto):
        result.message = "Target Reached" #É um dos campos customs do arquivo .action
        goal_handle.succeed()
        return result





def main(args=None):
    rclpy.init(args=args)
    count_server_node = CountServerNode()


if __name__ == "__main__":
    main()