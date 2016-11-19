
#include "Ball.hpp"


Ball::Ball(){
    initFlag = true;
    x = 1.0;
    y = 0;
    z = 1.0;
    speed = 0;
    pow = 0;
}

void Ball::MakeBall(double height, GLfloat* color){
//    glPushMatrix();
    glTranslated(0.0, height, 0.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
    glutSolidSphere(BALL_RANGE, 8, 8);
//    glPopMatrix();
    
}

void Ball::InitPos(int ballNumber){
    pos[X] = initPos[ballNumber][X];
    pos[Y] = initPos[ballNumber][Y];
    pos[Z] = initPos[ballNumber][Z];
    initFlag = false;
}

void Ball::Move(){
    
    pos[X] += x * speed;
 //   pos[Y] += vec[Y] * speed;
    pos[Z] += z * speed;

}

void Ball::RefrectWall(){
    if(pos[X] > TABLE_WIDTH - BALL_RANGE || pos[X] < -TABLE_WIDTH +BALL_RANGE){
        x *= -1;
        printf("checkX");
    }
    if(pos[Z] > TABLE_DEPTH - BALL_RANGE+0.25 || pos[Z] < -TABLE_DEPTH + BALL_RANGE + 0.5){
        z *= -1;
        printf("check");
        
    }
    
}

Vector3d Ball::setVec(){
    Vector3d arcVec(x,y,z);
    return arcVec;
}

