import cv2
import numpy as np

class CameraVisionModule:
    def __init__(self,CameraNumber):
        self.Camera_Cap=cv2.VideoCapture(CameraNumber)
        _,self.Frame = self.Camera_Cap.read()
        self.Camera_Cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.Camera_Cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.Center_X=self.Frame.shape[1] // 2
        self.Center_Y=self.Frame.shape[0] // 2

    def Read_Frame(self):
        _,self.Frame=self.Camera_Cap.read()
#        self.Frame = self.Frame[0:100, 100:500]


    def Hsv_Frame(self):
        return cv2.cvtColor(self.Frame,cv2.COLOR_BGR2HSV)
    
    def Red_Blue(self,data):
            if data == "red":
                Lower_Red = np.array([160, 122, 0])
                Upper_Red = np.array([180, 255, 255])
                Mask=self.Hsv_Frame()
                return cv2.inRange(Mask,Lower_Red,Upper_Red)
            else:
                Lower_Blue = np.array([80, 70, 10])
                Upper_Blue = np.array([140, 255, 255])
                Mask=self.Hsv_Frame()
                return cv2.inRange(Mask,Lower_Blue,Upper_Blue)
    
    def Distance_Center_Frame(self,cX_Contour,cY_Contour):
        Dis=[]
        Distance = np.sqrt((cX_Contour - self.Center_X) ** 2 + (cY_Contour - self.Center_Y) ** 2)
        Dis.append(Distance)
        Min_Distance=min(Dis)
        #print("distance",Min_Distance)
        if(cX_Contour>self.Center_X):
            return ('+' + str(Min_Distance))
        else:
            return('-'+str(Min_Distance))

    def Detect_rectangle(self):
        gray = cv2.cvtColor(self.Frame, cv2.COLOR_BGR2GRAY)
        ret, thresh = cv2.threshold(gray,10,255,0)
        contours, hierarchy = cv2.findContours(thresh, 1, 2)
        for cnt in contours:
            x1, y1 = cnt[0][0]
            approx = cv2.approxPolyDP(cnt, 0.01*cv2.arcLength(cnt, True), True)
            if len(approx) == 4:
                x, y, w, h = cv2.boundingRect(cnt)
                ratio = float(w)/h
                print("ok")
                if ratio >= 0.9 and ratio <= 1.1:
                    frame = cv2.drawContours(self.Frame, [cnt], -1, (0,255,255), 3)
                    cv2.putText(frame, 'Square', (x1, y1), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 0), 2)
                else:
                    cv2.putText(frame, 'Rectangle', (x1, y1), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)
                    frame = cv2.drawContours(self.Frame, [cnt], -1, (0,255,0), 3)

    def Detect_Shape(self):
        Color_Mask=self.Red_Blue('blue')
        kernel=np.ones((5,5),np.uint8)
        Mask_kernel=cv2.erode(Color_Mask,kernel)
        contours,_=cv2.findContours(Mask_kernel,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
        for cnt in contours:
            area=cv2.contourArea(cnt)
            approx=cv2.approxPolyDP(cnt,0.01*cv2.arcLength(cnt,True),True)
            x=approx.ravel()[0]
            y=approx.ravel()[1]
            if area>2000:
                cv2.drawContours(self.Frame,[approx],0,(0,255,0),3)
                if 3<len(approx)<5:
                    cv2.putText(self.Frame,"Rectangle",(x,y),cv2.FONT_HERSHEY_COMPLEX,0.7,(0,0,0),cv2.LINE_4)
                elif 8<len(approx)<16:
                    cv2.putText(self.Frame,"Circle",(x,y),cv2.FONT_HERSHEY_COMPLEX,0.7,(0,0,0),cv2.LINE_4)
                    Mm=cv2.moments(cnt)
                    cX=int(Mm['m10']/Mm['m00'])
                    cY=int(Mm['m10']/Mm['m00'])
                    Dis=self.Distance_Center_Frame(cX,cY)
                   # print(area)

def main(): 
        Cam_obj=CameraVisionModule(0)
        qcd = cv2.QRCodeDetector()
        count = 0
        while True:
            Cam_obj.Read_Frame()
            ret,points,qrcode = qcd.detectAndDecode(Cam_obj.Frame)
            if ret:
                print("seen",count)
                count+=1
            #Cam_obj.Detect_Shape()
            Cam_obj.Detect_rectangle()
            cv2.imshow("code_test",Cam_obj.Frame)
            if cv2.waitKey(1) == ord('q'):
                Cam_obj.Camera_Cap.release()
                cv2.DestroyAllWindows()
                break
            
if __name__ == "__main__":
    main()
