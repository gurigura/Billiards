/*カメラ管理*/

#include "Camera.hpp"

/*カメラ位置初期化*/
void CameraInit(){
        cameraPos.x = 0.0;
        cameraPos.y = 0.0;
        cameraPos.z = -5.0;
}

/*カメラ移動　右*/
void RightMoveCamera(){
    cameraPos.x += 0.1;
}

/*カメラ移動　左*/
void LeftMoveCamera(){
    cameraPos.x -= 0.1;
}

/*カメラ移動　前*/
void FrontMoveCamera(){
    cameraPos.z -= 0.1;
}

/*カメラ移動　後*/
void BackMoveCamera(){
    cameraPos.z += 0.1;
}

/*カメラ移動　上*/
void UpMoveCamera(){
    cameraPos.y += 0.1;
}

/*カメラ移動　下*/
void DownMoveCamera(){
    cameraPos.y -= 0.1;
}