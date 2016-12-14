

#include "Pocket.hpp"


Pocket::Pocket(){
    GLfloat initPosSet[6][3] = {
        {-TABLE_WIDTH+0.01f, 0, -TABLE_DEPTH+0.01f}, //1
        { TABLE_WIDTH-0.01f, 0, -TABLE_DEPTH+0.01f}, //2
        {-TABLE_WIDTH+0.01f, 0, 0},  //3
        { TABLE_WIDTH-0.01f, 0, 0},  //4
        {-TABLE_WIDTH+0.01f, 0, TABLE_DEPTH-0.01f}, //5
        { TABLE_WIDTH-0.01f, 0, TABLE_DEPTH-0.01f}, //6
        };
    
    for(int i=0;i<BALL_NUM;i++){
        for(int j=0;j<3;j++){
            initPos[i][j] = initPosSet[i][j];
        }
    }
    
    color [0] = 0.0;
    color [1] = 0.0;
    color [2] = 0.0;
    color [3] = 0.0;
    
}


void Pocket::MakePocket(double height){
    glPushMatrix();
    glTranslated(pos.x, height, pos.z);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
    glutSolidSphere(BALL_RANGE*1.5, 16, 16);
    glPopMatrix();
    
}

void Pocket::InitPos(int ballNumber){
    pos.x = initPos[ballNumber][X];
    pos.y = initPos[ballNumber][Y];
    pos.z = initPos[ballNumber][Z];
}