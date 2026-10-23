import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from custom_action_interfaces.action import Fibonacci

class FibonnaciActionServer(Node):

    def __init__(self):
        super().__init__('fibonacci_action_server')
        self._action_server = ActionServer(
            self,
            Fibonacci,
            'fibonacci',
            self.execute_callback)
        


    def execute_callback(self, goal_handle):
        #ESta versão nao tem feedback. Para ter feedback, deve ser explicitamente feito isso.

        self.get_logger().info("executing goal...")
        sequence = [0,1]

        for i in range(1, goal_handle.request.order):
            sequence.append(sequence[i] + sequence[i-1])

        #Indicate that the goals as sucessful (reached)
        goal_handle.succeed()

        #Assign the sequence to the result message to return the result to the client.
        result = Fibonacci.Result()
        result.sequence = sequence
        return result #Return sempre é do tipo RESULT (Neste caso, o que é indicado no arquivo .action---> Fibonacci.Result


def main(args = None):
    rclpy.init(args=args)
    fibonacci_action_server = FibonnaciActionServer()
