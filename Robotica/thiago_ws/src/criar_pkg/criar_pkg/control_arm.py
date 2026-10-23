import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
import time

from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint

class ArmController(Node):

    def __init__(self):
        super().__init__("arm_controller")
        self.arm_pub = self.create_publisher(
            JointTrajectory, 
            "/arm_controller/joint_trajectory",
            1
            )
        
        self.cmd = JointTrajectory()
        self.cmd.joint_names = [
            "arm_1_joint", "arm_2_joint",
            "arm_3_joint", "arm_4_joint",
            "arm_5_joint", "arm_6_joint",
            "arm_7_joint"
            ]

        time.sleep(2)



def main(args = None):

    rclpy.init(args=args)
    my_controller = ArmController()

    #Fill the message with the trajectory. It is composed of joint trajectory points.
    point =JointTrajectoryPoint() 
    #Each index is to one joint. In this example, thiagows, the robot has 7 joints.
    point.positions = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0] #Radians of each joint.
    point.time_from_start.sec = 5
    my_controller.cmd.points = [point]
    my_controller.cmd.joint_names = [
            "arm_1_joint", "arm_2_joint",
            "arm_3_joint", "arm_4_joint",
            "arm_5_joint", "arm_6_joint",
            "arm_7_joint"
            ]

    #publish the msg
    my_controller.arm_pub.publish(my_controller.cmd)
    time.sleep(6)
    my_controller.get_logger().info("ARM MOVED!!!!")
    rclpy.shutdown()


if __name__ == "__main__":
    main()