import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import time
import math
from visualization_msgs.msg import Marker


class ProcessLaser(Node):
    def __init__(self):
        super().__init__("process_laser")
        # Subscribe to read the pose
        self.laser_sub = self.create_subscription(LaserScan, "/scan_raw", self.laser_callback, 10)
        self.marker_pub = self.create_publisher(Marker, '/closest_point', 1)
        self.marker_msg = Marker()

        #COnfigurin marker
        #IMPORTANTE Referencial do medidor de distancia é a ferramenta, não a base do sensor.
        #Isso pode causar alguns problemas caso não tratado, 
        # pois a referencia (translação, rotação) são diferente.
        #self.marker_msg.header.frame_id = 'base_link' #Should not be base link. REference should be the laser tool reference.
        self.marker_msg.header.frame_id = 'base_laser_link'
        self.marker_msg.header.stamp = self.get_clock().now().to_msg()

        self.marker_msg.ns = 'target'
        self.marker_msg.id = 0
        self.marker_msg.type = Marker.SPHERE
        self.marker_msg.action = Marker.ADD

        #Desired pos in the base link. Basically, the ref frame in meters
        self.marker_msg.pose.position.x = 0.0
        self.marker_msg.pose.position.y = 0.0
        self.marker_msg.pose.position.z = 0.0
        self.marker_msg.pose.orientation.w = 1.0

        #Editing sphere that represents the marker
        self.marker_msg.scale.x = 0.05
        self.marker_msg.scale.y = 0.05
        self.marker_msg.scale.z = 0.05

        self.marker_msg.color.r = 0.0
        self.marker_msg.color.g = 0.0
        self.marker_msg.color.b = 1.0
        self.marker_msg.color.a = 1.0





        #

    
    def laser_callback(self, msg : LaserScan):
        angle_min = msg.angle_min
        angle_max = msg.angle_max
        angle_increment = msg.angle_increment
        
        #print(angle_min, angle_max)
        nb_points = math.ceil(angle_max - angle_min) / (angle_increment + 1)
        
        #print(math.degrees(angle_min), math.degrees(angle_max), math.degrees(angle_increment), nb_points)
        min_range = 1000
        min_index = 0
        for i, r in enumerate(msg.ranges):
            if r < min_range:
                min_range = r
                min_index = i

        #print(min_range, min_index)

        #Convert polar to eucledian coordinates
        #Using trigonometric again : x = cos(teta) * raio. Raio neste caso é a distancia ate o ponto.
        min_a = angle_min + min_index*angle_increment
        min_x = math.cos(min_a) * min_range
        min_y = math.sin(min_a) * min_range
        print(f"Min point is at {round(min_x, 4)},{round(min_y,4)}")

        #Para validar se o calculo está correto, iremos plotar, na simulação, um ponto (marcador)
        #This is done by using the marker msg
        self.marker_msg.pose.position.x = min_x
        self.marker_msg.pose.position.y = min_y

        self.marker_pub.publish(self.marker_msg)


        



def main(args=None):
    # Star the node
    rclpy.init(args=args)
    
    # Instantiate a controller from class
    process_laser = ProcessLaser()
    
    rclpy.spin(process_laser)
    
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()