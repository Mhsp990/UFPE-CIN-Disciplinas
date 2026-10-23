import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
import time
import math

from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint

class HeadController(Node):

    def __init__(self):
        super().__init__("head_controller")
        self.head_pub = self.create_publisher(
            JointTrajectory, 
            "/head_controller/joint_trajectory",
            1
            )
        
        self.cmd = JointTrajectory()
        self.cmd.joint_names = [
            "head_1_joint", "head_2_joint",
            ]

        time.sleep(2)


def main(args = None):

    rclpy.init(args=args)
    my_controller = HeadController()

    #Fill the message with the trajectory. It is composed of joint trajectory points.
    point =JointTrajectoryPoint() 
    #Each index is to one joint. The head has two joints.
    point.positions = [math.radians(90), 0] #Radians of each joint.
    point.time_from_start.sec = 5

    point_2 = JointTrajectoryPoint()
    point_2.positions = [math.radians(20), 0]
    point_2.time_from_start.sec = 10 # It will execute 5 seconds AFTER the first, since it is FROM START

    my_controller.cmd.points = [point, point_2]

    #publish the msg
    my_controller.head_pub.publish(my_controller.cmd)
    time.sleep(6)
    my_controller.get_logger().info("HEAD MOVED!!!!")
    rclpy.shutdown()


if __name__ == "__main__":
    main()