/*ボール挙動管理*/

#include "Ball.hpp"

Ball::Ball(){
    initFlag = true;
    x = 0.0;
    y = 0.0;
    z = 0.0;
    pow = 0;
}

/*ボール描画*/
void Ball::MakeBall(double height, GLfloat* color){
//    glPushMatrix();
    glTranslated(0.0, height, 0.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
    glutSolidSphere(BALL_RANGE, 8, 8);
//    glPopMatrix();
    
}

/*ボール位置初期化*/
void Ball::InitPos(int ballNumber){
    pos[X] = initPos[ballNumber][X];
    pos[Y] = initPos[ballNumber][Y];
    pos[Z] = initPos[ballNumber][Z];
    initFlag = false;
}

/*ボール移動(座標変更)*/
void Ball::Move(){
    x *= FRICTION_FACTOR;
//    y *= FRICTION_FACTOR;
    z *= FRICTION_FACTOR;
    if(x*x + z*z < (1-FRICTION_FACTOR)/1000){ x=z=0;
    }else{
        pos[X] += x;
        pos[Y] += y;
        pos[Z] += z;
    }
}

/*壁反射　引数:GLdouble *pos */
void Ball::RefrectWall(GLdouble *argPos){
    
    if(pos[X] > TABLE_WIDTH - BALL_RANGE){
        pos[X] -= (pos[X] + BALL_RANGE) - TABLE_WIDTH;    //めり込んだ分戻す
        Vector3d test;
        x *= -1;
    }
    else if(pos[X] < -TABLE_WIDTH +BALL_RANGE){
        pos[X] -= (pos[X] - BALL_RANGE) + TABLE_WIDTH;    //めり込んだ分戻す
        x *= -1;
    }
    if(pos[Z] > TABLE_DEPTH - BALL_RANGE){
        pos[Z] -= (pos[Z] + BALL_RANGE) - TABLE_DEPTH;    //めり込んだ分戻す
        z *= -1;
    }
    else if(pos[Z] < -TABLE_DEPTH +BALL_RANGE ){
        pos[Z] -= (pos[Z] - BALL_RANGE) + TABLE_DEPTH;    //めり込んだ分戻す
        z *= -1;
    }
    
}

Vector3d Ball::getVec(){
    Vector3d arcVec(x,y,z);
    return arcVec;
}

