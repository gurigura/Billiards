/*ボール挙動管理*/

#include "Ball.hpp"

Ball::Ball(){
    initFlag = true;
    speed.x = 0.0;
    speed.y = 0.0;
    speed.z = 0.0;
    pow = 0;
    
    GLfloat initPosSet[BALL_NUM][3] = {
        {0, 0, TABLE_DEPTH/2}, //0
        {0, 0, -TABLE_DEPTH/2 + 2*BALL_RANGE*root3}, //1
        { BALL_RANGE*2,0, -TABLE_DEPTH/2},  //2
        {0, 0, (-TABLE_DEPTH/2) + (-2*BALL_RANGE*root3)},    //3
        {-BALL_RANGE*2,0, -TABLE_DEPTH/2},  //4
        { BALL_RANGE,  0, -TABLE_DEPTH/2 + BALL_RANGE*root3},  //5
        {-BALL_RANGE,  0, -TABLE_DEPTH/2 + BALL_RANGE*root3},  //6
        { BALL_RANGE,  0, -TABLE_DEPTH/2 - BALL_RANGE*root3},   //7
        {-BALL_RANGE,  0, -TABLE_DEPTH/2 - BALL_RANGE*root3},   //8
        {0,0, -TABLE_DEPTH/2}   //9
    };

    for(int i=0;i<BALL_NUM;i++){
        for(int j=0;j<3;j++){
            initPos[i][j] = initPosSet[i][j];
        }
    }
    
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
    pos.x = initPos[ballNumber][X];
    pos.y = initPos[ballNumber][Y];
    pos.z = initPos[ballNumber][Z];
    initFlag = false;
}

/*ボール移動(座標変更)*/
void Ball::Move(){
    speed *= FRICTION_GROUND;//摩擦抵抗
    /*一定速度以下で停止*/
    if(speed.x*speed.x + speed.z*speed.z < (1-FRICTION_GROUND)/1000)
    {
        speed.x=speed.z=0;
    }
    else
    {
        pos.x += speed.x;
        pos.y += speed.y;
        pos.z += speed.z;
    }
}

/*壁反射　引数:GLdouble *pos */
void Ball::RefrectWall(Vector3d &argPos){
    
    if(pos.x > TABLE_WIDTH - BALL_RANGE){
        pos.x -= (pos.x + BALL_RANGE) - TABLE_WIDTH;    //めり込んだ分戻す
        speed.x *= -1;
    }
    else if(pos.x < -TABLE_WIDTH +BALL_RANGE){
        pos.x -= (pos.x - BALL_RANGE) + TABLE_WIDTH;
        speed.x *= -1;
    }
    if(pos.z > TABLE_DEPTH - BALL_RANGE){
        pos.z -= (pos.z + BALL_RANGE) - TABLE_DEPTH;
        speed.z *= -1;
    }
    else if(pos.z < -TABLE_DEPTH +BALL_RANGE ){
        pos.z -= (pos.z - BALL_RANGE) + TABLE_DEPTH;
        speed.z *= -1;
    }
    
}

Vector3d Ball::getVec(){
    Vector3d argVec(speed.x,speed.y,speed.z);
    return argVec;
}

