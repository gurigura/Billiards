
#ifndef main_h
#define main_h

#include "Define.hpp"   /*定義ヘッダー*/
#include "Draw.hpp"     /*描画クラス*/
#include "Ball.hpp"     /*ボール挙動管理(ボールの描画はこっち)*/
#include "Pocket.hpp"   /*ポケット*/
#include "Color.hpp"    /*カラーコード*/
#include "Camera.hpp"   /*カメラ挙動処理*/
#include "Physics.hpp"  /*物理制御*/
#include "Vectror3d.hpp"    /*ベクトルクラス　Ball,Physicsに継承済み*/
#include "FpsMonitor.hpp"   /*FPS制御*/
#include "GameControl.hpp"  /*ゲームコントローラー*/


//#include<iostream>      /**/
//#include<thread>        /*スレッド管理*/
//#include<chrono>        /*時間管理*/

using namespace std;

#endif /* main_h */
