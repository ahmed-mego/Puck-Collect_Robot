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
        self.color = 'red'  

    def readFrame(self) :
        _,self.Frame = self.Camera_Cap.read()
        return _
        
    def hsvFrame(self,frame) :
        return cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    def redORblue(self,data,frame) :
            if data == 0 : # red detect 
                Lower_Red = np.array([160, 81, 92])
                Upper_Red = np.array([180, 255, 255])
                Mask = self.hsvFrame(frame)
                return cv2.inRange(Mask,Lower_Red, Upper_Red)
            elif data == 1: # blue detect 
                Lower_Blue = np.array([90, 70, 10])
                Upper_Blue = np.array([140, 255, 255])
                Mask=self.hsvFrame(frame)
                return cv2.inRange(Mask,Lower_Blue,Upper_Blue)
            else:           # green detect
                Lower_green = np.array([40, 200, 20])
                Upper_green = np.array([70, 255, 255])
                Mask=self.hsvFrame(frame)
                return cv2.inRange(Mask,Lower_green,Upper_green)

    def colorDetect(self):     # 0 -> Red 1 -> Blue 2 -> Green
        color_list = []
        for i in range(3):
            Frame = self.Frame[0:100, 100:500] 
            target_area  = 2000
            if i == 2:
                Frame = self.Frame[100:200, 370:400]  
                target_area = 100 
                # Frame for detect green rectangle for calibrate sorter
                 # Frame for detect red or blue pucks

            Color_Mask = self.redORblue(i,Frame)
            kernel = np.ones((5,5), np.uint8)
            Mask_kernel = cv2.erode(Color_Mask, kernel)
            contours,_ = cv2.findContours(Mask_kernel, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
            for cnt in contours :
                area = cv2.contourArea(cnt)
                #approx = cv2.approxPolyDP(cnt, 0.01 * cv2.arcLength(cnt, True), True)
                # x = approx.ravel()[0]
                # y = approx.ravel()[1] 
                if area >  target_area:
                    color_list.append(i)
                    break     # detected color value
        if len(color_list) == 0:
            return 3,color_list
        return 0,color_list
        

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
            detectoutput,color_list = Cam_obj.colorDetect()
            if detectoutput == 0:
                for color in color_list:
                    msg.data = color
                    minimal_publisher.publish(msg)
            else:
                msg.data = 3
                minimal_publisher.publish(msg)
            # if  detectoutput == 0 :# red:
                
            #     msg.data = 0
            #     minimal_publisher.publish(msg)
            #     #sleep(2)
                
            # elif  detectoutput == 1: # blue:
                
            #     msg.data = 1
            #     minimal_publisher.publish(msg)
            #     #sleep(2)
            # elif detectoutput == 2:
            #     msg.data = 2
            #     minimal_publisher.publish(msg)
            #     #sleep(2)

            # else :
            #     msg.data = 3
            #     minimal_publisher.publish(msg)
        #minimal_publisher.get_logger().info('Publishing: "%s"' % msg)
        sleep(1/30)

    Cam_obj.Camera_Cap.release()
    cv2.DestroyAllWindows()
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
