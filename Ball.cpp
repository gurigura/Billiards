/*ボール挙動管理*/

#include "Ball.hpp"

Ball::Ball(){
    initFlag = true;
    vec.x = 0.0;
    vec.y = 0.0;
    vec.z = 0.0;
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
    vec *= FRICTION_GROUND;//摩擦抵抗
    /*一定速度以下で停止*/
    if(vec.x*vec.x + vec.z*vec.z < (1-FRICTION_GROUND)/1000)
    {
        vec.x=vec.z=0;
    }
    else
    {
        pos[X] += vec.x*BALL_WEIGHT;
        pos[Y] += vec.y*BALL_WEIGHT;
        pos[Z] += vec.z*BALL_WEIGHT;
    }
}

/*壁反射　引数:GLdouble *pos */
void Ball::RefrectWall(GLdouble *argPos){
    
    if(pos[X] > TABLE_WIDTH - BALL_RANGE){
        pos[X] -= (pos[X] + BALL_RANGE) - TABLE_WIDTH;    //めり込んだ分戻す
        vec.x *= -1;
    }
    else if(pos[X] < -TABLE_WIDTH +BALL_RANGE){
        pos[X] -= (pos[X] - BALL_RANGE) + TABLE_WIDTH;
        vec.x *= -1;
    }
    if(pos[Z] > TABLE_DEPTH - BALL_RANGE){
        pos[Z] -= (pos[Z] + BALL_RANGE) - TABLE_DEPTH;
        vec.z *= -1;
    }
    else if(pos[Z] < -TABLE_DEPTH +BALL_RANGE ){
        pos[Z] -= (pos[Z] - BALL_RANGE) + TABLE_DEPTH;
        vec.z *= -1;
    }
    
}

Vector3d Ball::getVec(){
    Vector3d arcVec(vec.x,vec.y,vec.z);
    return arcVec;
}

