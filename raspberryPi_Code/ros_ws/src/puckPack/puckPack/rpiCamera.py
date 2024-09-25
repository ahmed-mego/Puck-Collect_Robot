import rclpy
from rclpy.node import Node
from std_msgs.msg import Int8
import cv2
import numpy as np
from time import sleep



class CameraVisionModule :
    def __init__(self,CameraNumber) :
        self.Camera_Cap = cv2.VideoCapture(CameraNumber)
        _,self.Frame = self.Camera_Cap.read()
        self.Camera_Cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.Camera_Cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.Center_X = self.Frame.shape[1] // 2
        self.Center_Y = self.Frame.shape[0] // 2
        self.color = 'red'

    def readFrame(self) :
        _,self.Frame = self.Camera_Cap.read()
        self.Frame = self.Frame[0:100, 100:500]

        
        return _
    def hsvFrame(self) :
        return cv2.cvtColor(self.Frame, cv2.COLOR_BGR2HSV)
    
    def redORblue(self,data) :
            if data == 0 : # red detect 
                Lower_Red = np.array([160, 81, 92])
                Upper_Red = np.array([180, 255, 255])
                Mask = self.hsvFrame()
                return cv2.inRange(Mask,Lower_Red, Upper_Red)
            elif data == 1: # blue detect 
                Lower_Blue = np.array([90, 70, 10])
                Upper_Blue = np.array([140, 255, 255])
                Mask=self.hsvFrame()
                return cv2.inRange(Mask,Lower_Blue,Upper_Blue)

    def colorDetect(self):
        for i in range(2):
            Color_Mask = self.redORblue(i)
            kernel = np.ones((5,5), np.uint8)
            Mask_kernel = cv2.erode(Color_Mask, kernel)
            contours,_ = cv2.findContours(Mask_kernel, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
            for cnt in contours :
                area = cv2.contourArea(cnt)
                approx = cv2.approxPolyDP(cnt, 0.01 * cv2.arcLength(cnt, True), True)
                x = approx.ravel()[0]
                y = approx.ravel()[1]
                if area > 2000 :
                    return i     #detected color value
                
        return 2
        

class MinimalPublisher(Node):

    def __init__(self,camera):
        super().__init__('raspberryCam')
        self.publisher_ = self.create_publisher(Int8, 'rpi_cam', 10)
        self.camera = camera 
    def publish(self,msg):
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)

    Cam_obj = CameraVisionModule(0)

    minimal_publisher = MinimalPublisher(Cam_obj)
    msg = Int8()
    while rclpy.ok():
        if minimal_publisher.camera.readFrame():
            detectoutput = Cam_obj.colorDetect()
            if  detectoutput == 0 :# red:
                
                msg.data = 0
                minimal_publisher.publish(msg)
                sleep(2)
                
            elif  detectoutput == 1: # blue:
                
                msg.data = 1
                minimal_publisher.publish(msg)
                sleep(2)
            else:
                msg.data = 2
                minimal_publisher.publish(msg)
        sleep(0.1)

    Cam_obj.Camera_Cap.release()
    cv2.DestroyAllWindows()
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
