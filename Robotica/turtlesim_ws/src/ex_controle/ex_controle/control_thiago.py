import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from turtlesim.msg import Pose

import time
import math

class MobileController(Node):

    def __init__(self):
        super().__init__("thiago_controller")

        # Publish to control the turtle simulator
        self.twist_pub = self.create_publisher(TwistStamped, "/mobile_base_controller/cmd_vel", 1)
        self.cmd = TwistStamped()
        
        # Subscribe to read the pose
        #self.pose_sub = self.create_subscription(Pose, "/turtle1/pose", self.pose_callback, 1)
        
        # Goal definition
        self.x_goal = 6
        self.y_goal = 6
        self.theta_goal = math.radians(45)
        
        self.state = 0
        
        time.sleep(1)
        
    # def pose_callback(self, msg):
        
    #     # Extract data
    #     x = msg.x
    #     y = msg.y
    #     theta = msg.theta
        
    #     print("Pose: ", x, y, theta)
        
    #     # Compute desired orientation
    #     theta_maneuver = math.atan2(self.y_goal - y, self.x_goal - x)
    #     print("theta goal:{}".format(math.degrees(theta_maneuver)))
        
    #     # Compute orientation error
    #     e_theta_maneuver = theta_maneuver - theta
        
    #     # Compute the distance error
    #     e_dist = math.sqrt((self.x_goal - x)**2 + (self.y_goal - y)**2)
        
    #     # Compute final orientation error
    #     e_theta_goal = self.theta_goal - theta
        
    #     K_theta  = 1
    #     K_dist = 0.5
    #     angularThreshold = math.radians(0.1)
    #     distanceThreshold = 0.005
        
    #     # Initial maneuver to orientate the robot
    #     if self.state == 0: 
    #         print("Orientation maneuver")
    #         self.cmd.linear.x = 0.0
    #         self.cmd.angular.z = K_theta * e_theta_maneuver
            
    #         next_state = self.state
    #         if (abs(e_theta_maneuver) < angularThreshold):
    #             next_state = 1
        
    #     # Drive towards the goal
    #     if self.state == 1:
    #         print("Distance")
    #         self.cmd.linear.x = K_dist*e_dist
    #         self.cmd.angular.z = K_theta * e_theta_maneuver
            
    #         next_state = self.state
    #         if (e_dist < distanceThreshold):
    #             next_state = 2
                
    #     # Turn towards the desired orientation
    #     if self.state == 2:
    #         print("Orientation final")
    #         self.cmd.linear.x = 0.0
    #         self.cmd.angular.z = K_theta * e_theta_goal
            
    #         next_state = self.state
    #         if (abs(e_theta_goal) < angularThreshold):
    #             next_state = 3
    #     # Stop the robot
    #     if self.state == 3:
    #         print("Stop")
    #         self.cmd.linear.x = 0.0
    #         self.cmd.angular.z = 0.0
    #         next_state = self.state
            
    #     # Update the state
    #     self.state = next_state
        
    #     # Publish the turtle command
    #     self.twist_pub.publish(self.cmd)
        
def main(args=None):

    # Star the node
    rclpy.init(args=args)
    
    # Instantiate a controller from class
    mycontroller = MobileController()
    
    # rclpy.spin(mycontroller)
    
    # rclpy.shutdown()
    
    # Indicate a velocity
    mycontroller.cmd.twist.linear.x = 0.5 # m/s
    
    # Publish the msg
    #mycontroller.twist_pub.publish(mycontroller.cmd)
    
    # Wait for one second
    time.sleep(1)
    
    # Indicate a velocity
    mycontroller.cmd.twist.linear.x = 0.0 # m/s
    
    # Publish the msg
    mycontroller.twist_pub.publish(mycontroller.cmd)
    
    #time.sleep(0.5)
    
if __name__ == "__main__":
    main()