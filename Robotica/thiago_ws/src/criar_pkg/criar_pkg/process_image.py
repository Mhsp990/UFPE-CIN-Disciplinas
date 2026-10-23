import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
# import time
# import math
# from visualization_msgs.msg import Marker
import cv2
from cv_bridge import CvBridge, CvBridgeError



class ProcessImage(Node):
    def __init__(self):
        super().__init__("process_image")
        self.bridge = CvBridge()
        # Subscribe 
        self.image_sub = self.create_subscription(Image, "/head_front_camera/image", self.image_callback, 10)

        self.image_modified_pub = self.create_publisher(Image, '/my_modified_image',1)
      

    
    def image_callback(self, msg : Image):
        #ROS2 TO OPENCV
        image = self.bridge.imgmsg_to_cv2(msg,desired_encoding="bgr8")
        # cv2.imshow('camera', image)
        # cv2.waitKey(1)

        # Image dimensions
        height, width, channels = image.shape

        #Pecorre a imagem. Primeiro indice é coluna (y), dps linha (x), dps canal (BGR). [y,x, 0] acessa o canal blue do pixel em y,x
        for y in range(height):
            for x in range(width):
                b, g, r = image[y,x]
                #Vamos converter todos os pixeis da bolha VERMELHA ("puramente" vermelha) para outra cor.. 
                # Para isso, usamos um limiar que permita identificar apena a bola via valor dos pixels.
                if (b < 10 and g < 10 and (r >= 160 and r <= 220)):
                    image[y,x] = 128, 200, 50


        # print(height, width, channels)

        #Agora, transmitir a imagem modificada. OPen cv para ros
        image_ros = self.bridge.cv2_to_imgmsg(image, encoding='bgr8') #Já gera uma mensagem.
        self.image_modified_pub.publish(image_ros)


def main(args=None):
    # Star the node
    rclpy.init(args=args)
    
    # Instantiate a controller from class
    process_image = ProcessImage()
    
    rclpy.spin(process_image)
    
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()