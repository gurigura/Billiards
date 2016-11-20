/*カメラ管理*/

#include "Camera.hpp"

/*カメラ位置初期化*/
void CameraInit(){
        cameraPos[0] = 0.0;
        cameraPos[1] = 0.0;
        cameraPos[2] = -5.0;
}

/*カメラ移動　右*/
void RightMoveCamera(){
    cameraPos[0] += 0.1;
    
}

/*カメラ移動　左*/
void LeftMoveCamera(){
    cameraPos[0] -= 0.1;
}

/*カメラ移動　前*/
void FrontMoveCamera(){
    cameraPos[2] -= 0.1;
}

/*カメラ移動　後*/
void BackMoveCamera(){
    cameraPos[2] += 0.1;
}

/*カメラ移動　上*/
void UpMoveCamera(){
    cameraPos[1] += 0.1;
}

/*カメラ移動　下*/
void DownMoveCamera(){
    cameraPos[Y] -= 0.1;
}