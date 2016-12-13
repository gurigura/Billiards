
#ifndef Define_h
#define Define_h

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>

#include "Vectror3d.hpp"


const static float TABLE_WIDTH = 0.695;   /*台の幅/2 */
const static float TABLE_DEPTH = 1.37;    /*台の長さ/2 */
const static float TABLE_HEIGHT = 0.5; /*壁の高さ */
const static float BALL_RANGE =  0.057;   /*ボールの半径*/
const static int BALL_NUM = 10; /*ボールの数 + 1*/
const static float BALL_WEIGHT = 0.175;  /*球の質量*/
const static float FRICTION_GROUND = 0.990;      /*台との摩擦係数(1-(10^-2))*/
const static float FRICTION_WALL = 0.990;      /*壁との摩擦係数(1-(10^-2))*/
const static float FRICTION_BALL = 0.999;      /*球との摩擦係数(1-(10^-3))*/

const static float PI = 3.141592;
const static float root3 = 1.73205080757;   /*初期位置の縦の距離の割合*/

/*座標系配列番号*/
const static int X = 0;
const static int Y = 1;
const static int Z = 2;

//#define TIMESCALE   0.01    /*フレーム間隔*/

#endif
