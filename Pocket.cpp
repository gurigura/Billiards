

#include "Pocket.hpp"


Pocket::Pocket(){
    GLfloat initPosSet[6][3] = {
        {-TABLE_WIDTH, 0, -TABLE_DEPTH}, //1
        { TABLE_WIDTH, 0, -TABLE_DEPTH}, //2
        {-TABLE_WIDTH, 0, 0},  //3
        { TABLE_WIDTH, 0, 0},  //4
        {-TABLE_WIDTH, 0, TABLE_DEPTH}, //5
        { TABLE_WIDTH, 0, TABLE_DEPTH}, //6
        };
    
    for(int i=0;i<BALL_NUM;i++){
        for(int j=0;j<3;j++){
            initPos[i][j] = initPosSet[i][j];
        }
    }
    
    color [0] = 0.9;
    color [1] = 0.9;
    color [2] = 0.9;
    color [3] = 0.9;
    
}


void Pocket::MakePocket(double height){
    glPushMatrix();
    glTranslated(pos.x, height, pos.z);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
    glutSolidSphere(BALL_RANGE, 16, 16);
    glPopMatrix();
    
}

void Pocket::InitPos(int ballNumber){
    pos.x = initPos[ballNumber][X];
    pos.y = initPos[ballNumber][Y];
    pos.z = initPos[ballNumber][Z];
}