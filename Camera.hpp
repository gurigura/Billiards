
#ifndef Camera_hpp
#define Camera_hpp

#include "Define.hpp"

/*カメラ位置変数*/
static GLfloat cameraPos[3] = {0.0,0.0,-5.0};   //X,Y,Z

/*カメラ初期位置*/
void CameraInit();

///@@@  1つの関数にした方がいいのか
void RightMoveCamera(); /*カメラ移動　右*/
void LeftMoveCamera();  /*カメラ移動　左*/
void FrontMoveCamera(); /*カメラ移動　前*/
void BackMoveCamera();  /*カメラ移動　後*/
void UpMoveCamera();    /*カメラ移動　上*/
void DownMoveCamera();  /*カメラ移動　下*/
#endif /* Camera_hpp */
