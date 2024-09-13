import cv2
import numpy as np

class CameraVisionModule :
    def __init__(self,CameraNumber) :
        self.Camera_Cap = cv2.VideoCapture(CameraNumber,0)
        _,self.Frame = self.Camera_Cap.read()
        self.Camera_Cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.Camera_Cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.Center_X = self.Frame.shape[1] // 2
        self.Center_Y = self.Frame.shape[0] // 2

    def Read_Frame(self) :
        _,self.Frame = self.Camera_Cap.read()

    def Hsv_Frame(self) :
        return cv2.cvtColor(self.Frame, cv2.COLOR_BGR2HSV)
    
    def Red_Blue(self,data) :
            if data == "red" :
                Lower_Red = np.array([160, 81, 92])
                Upper_Red = np.array([180, 255, 255])
                Mask=self.Hsv_Frame()
                return cv2.inRange(Mask,Lower_Red, Upper_Red)
            else:
                Lower_Blue = np.array([110, 50, 50])
                Upper_Blue = np.array([180, 255, 255])
                Mask=self.Hsv_Frame()
                return cv2.inRange(Mask,Lower_Blue,Upper_Blue)
    
    def Distance_Center_Frame(self,cX_Contour,cY_Contour) :
        Dis=[]
        Distance = np.sqrt((cX_Contour - self.Center_X) ** 2 + (cY_Contour - self.Center_Y) ** 2)
        Dis.append(Distance)
        Min_Distance = min(Dis)
        print("distance", Min_Distance)
        if(cX_Contour > self.Center_X):
            return ('+' + str(Min_Distance))
        else:
            return('-' + str(Min_Distance))

    def puckDetect(self):
        Color_Mask = self.Red_Blue('red')
        kernel = np.ones((5,5), np.uint8)
        Mask_kernel = cv2.erode(Color_Mask, kernel)
        contours,_ = cv2.findContours(Mask_kernel, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
        for cnt in contours :
            area = cv2.contourArea(cnt)
            approx = cv2.approxPolyDP(cnt, 0.01 * cv2.arcLength(cnt, True), True)
            x=approx.ravel()[0]
            y=approx.ravel()[1]
            if area>600 :
                cv2.drawContours(self.Frame, [approx], 0, (0, 255, 0), 3)
                if 3 < len(approx) < 5 :
                    cv2.putText(self.Frame, "Rectangle", (x,y), cv2.FONT_HERSHEY_COMPLEX, 0.7, (0, 0, 0), cv2.LINE_4)
                elif 8 < len(approx) < 16 :
                    cv2.putText(self.Frame, "Circle" ,(x, y), cv2.FONT_HERSHEY_COMPLEX, 0.7, (0, 0, 0), cv2.LINE_4)
                    Mm = cv2.moments(cnt)
                    cX = int(Mm['m10'] / Mm['m00'])
                    cY = int(Mm['m10'] / Mm['m00'])
                    Dis = self.Distance_Center_Frame(cX, cY)
                    print(Dis)
        cv2.imshow("code_test", self.Frame)

def main(): 
        Cam_obj = CameraVisionModule(0)
        while True:
            Cam_obj.Read_Frame()
            Cam_obj.puckDetect()
            if cv2.waitKey(1) == ord('q'):
                Cam_obj.Camera_Cap.release()
                cv2.DestroyAllWindows()
                break
                
if __name__ == "__main__":
    main()