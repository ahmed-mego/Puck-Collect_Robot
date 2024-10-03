import rclpy
from rclpy.node import Node
from std_msgs.msg import Int8
import cv2
import numpy as np
from time import sleep


class CameraVisionModule:
    def __init__(self,CameraNumber):
  
        self.Camera_Cap = cv2.VideoCapture(CameraNumber,0)
        _,self.Frame = self.Camera_Cap.read()
        self.Camera_Cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.Camera_Cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.color = "red"

    def readFrame(self) :
        _,self.Frame = self.Camera_Cap.read()
        return _

    def hsvFrame(self) :
        return cv2.cvtColor(self.Frame, cv2.COLOR_BGR2HSV)
    
    def Red_OR_Blue(self,data) :
            if data == 0:  # red detect
                Lower_Red = np.array([160, 122, 0])
                Upper_Red = np.array([180, 255, 255])
                Mask=self.hsvFrame()
                return cv2.inRange(Mask,Lower_Red, Upper_Red)
            elif data == 1: # blue detect
                Lower_Blue = np.array([90, 70, 10])
                Upper_Blue = np.array([140, 255, 255])
                Mask=self.hsvFrame()
                return cv2.inRange(Mask,Lower_Blue,Upper_Blue)
    
    def Puck_OR_Base_R(self,seenl):
        Color_Mask = self.Red_OR_Blue(0)  # 0 -> red
        kernel = np.ones((5,5), np.uint8)
        Mask_kernel = cv2.erode(Color_Mask, kernel)
        contours,_ = cv2.findContours(Mask_kernel, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
        ret = 0
        for cnt in contours :
            area = cv2.contourArea(cnt)
            if area > 250 and area < 4000 :
                seenl[0] = 1
            elif area > 15000 and area < 100000 :
                seenl[2] = 1
        
                

    def Puck_OR_Base_B(self,seenl):
        Color_Mask = self.Red_OR_Blue(1) # 1 -> blue
        kernel = np.ones((5,5), np.uint8)
        Mask_kernel = cv2.erode(Color_Mask, kernel)
        contours,_ = cv2.findContours(Mask_kernel, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
        ret = 0
        for cnt in contours :
            area = cv2.contourArea(cnt)
            if area > 250 and area < 4000 :
                seenl[1] = 1
            elif area > 15000 and area < 100000 :
                seenl[3] = 1

                            
class MinimalPublisher(Node):

    def __init__(self,camera):
        super().__init__('mainCam')
        self.publisher_ = self.create_publisher(Int8, 'main_cam', 10)
        self.camera = camera 
    def publish(self,msg):
        self.publisher_.publish(msg) 

def main(args=None):

    rclpy.init(args=args)

    Cam_obj = CameraVisionModule(1)

    minimal_publisher = MinimalPublisher(Cam_obj)
    valuel = [1,2,4,8]
    while rclpy.ok() :
        seenl = [0,0,0,0]
        #print(Cam_obj.puckDetect())
        if minimal_publisher.camera.readFrame():
            minimal_publisher.camera.Puck_OR_Base_B(seenl)
            minimal_publisher.camera.Puck_OR_Base_R(seenl)
            msg = Int8()
            msg.data = 0
            for i in range(4):
                if seenl[i] == 1:
                    msg.data += valuel[i]   #when detect puck
            minimal_publisher.publish(msg)
            #minimal_publisher.get_logger().info('Publishing: "%s"' % seenl)

        sleep(1/30)

    Cam_obj.Camera_Cap.release()
    cv2.DestroyAllWindows()
    minimal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


"""


"""




# x=approx.ravel()[0]
            # # y=approx.ravel()[1]
            # if area > 100 :
            #     # cv2.drawContours(self.Frame, [approx], 0, (0, 255, 0), 3)
            #     if 3 < len(approx) < 5 :
            #         # cv2.putText(self.Frame, "Base", (x,y), cv2.FONT_HERSHEY_COMPLEX, 0.7, (0, 0, 0), cv2.LINE_4)
            #     elif 8 < len(approx):
            #         # cv2.putText(self.Frame, "Puck" ,(x, y), cv2.FONT_HERSHEY_COMPLEX, 0.7, (0, 0, 0), cv2.LINE_4)
            #         Mm = cv2.moments(cnt)
            #         cX = int(Mm['m10'] / Mm['m00'])
            #         cY = int(Mm['m10'] / Mm['m00'])
            #         #Dis = self.Distance_Center_Frame(cX, cY)
            #     ret =1
            # return ret 