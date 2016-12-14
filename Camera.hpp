/*カメラ管理*/

#ifndef Camera_hpp
#define Camera_hpp

#include "Define.hpp"

/*カメラ位置変数*/
static Vector3d cameraPos; //カメラ位置


/*カメラ初期位置*/
void CameraInit();

void RightMoveCamera(); /*カメラ移動　右*/
void LeftMoveCamera();  /*カメラ移動　左*/
void FrontMoveCamera(); /*カメラ移動　前*/
void BackMoveCamera();  /*カメラ移動　後*/
void UpMoveCamera();    /*カメラ移動　上*/
void DownMoveCamera();  /*カメラ移動　下*/
#endif /* Camera_hpp */
