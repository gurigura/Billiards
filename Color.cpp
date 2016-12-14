
#include "Color.hpp"

BallColor::BallColor(){
    GLfloat  colorCodeInit[10][4]  = {
        {1.0, 1.0, 1.0, 1.0},   //while[0]
        {0.9, 0.9, 0.2, 1.0},   //yellow[1]
        {0.0, 0.0, 1.0, 1.0},   //blue[2]
        {1.0, 0.0, 0.0, 1.0},   //red[3]
        {0.5, 0.0, 0.5, 1.0},   //purple[4]
        {1.0, 0.5, 0.0, 1.0},   //orange[5]
        {0.0, 1.0, 0.0, 1.0},   //green[6]
        {0.5, 0.0, 0.0, 1.0},   //brown[7]
        {1.0, 1.0, 0.5, 1.0},   //yellow2[8]
        {0.0, 1.0, 1.0, 1.0}    //blue2;[9]
    };
    
    for(int i=0;i<BALL_NUM;i++){
        for(int j=0;j<4;j++){
            colorCode[i][j] = colorCodeInit[i][j];
        }
    }
     GLfloat groundColorInit[4] = {0.0, 0.5, 0.0, 1.0};   //green2
    for(int j=0;j<4;j++)groundColor[j] = groundColorInit[j];
    
}