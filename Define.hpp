
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>

#include "Vectror3d.hpp"


#define TABLE_WIDTH 0.695   /*台の幅/2 */
#define TABLE_DEPTH 1.37    /*台の長さ/2 */
#define TABLE_HEIGHT 0.5 /*壁の高さ */
#define BALL_RANGE 0.057    /*ボールの半径*/
#define BALL_NUM 10 /*ボールの数 + 1*/
#define BALL_WEIGHT 0.175  /*球の質量*/
#define FRICTION_GROUND 0.990      /*台との摩擦係数(1-(10^-2))*/
#define FRICTION_WALL 0.990      /*壁との摩擦係数(1-(10^-2))*/
#define FRICTION_BALL 0.999      /*球との摩擦係数(1-(10^-3))*/

#define PI 3.141592

/*座標系配列番号*/
#define X 0
#define Y 1
#define Z 2

//#define TIMESCALE   0.01    /*フレーム間隔*/
