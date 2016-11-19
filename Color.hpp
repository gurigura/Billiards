//
//  color.hpp
//  OpenGL_Billiards
//
//  Created by Gurigura on 2016/11/15.
//  Copyright © 2016年 Guriguragurarira. All rights reserved.
//

#ifndef color_hpp
#define color_hpp

#include "Define.hpp"



class BallColor{

    private:
    
    public:
    
        GLfloat  colorCode[10][4]  = {
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
        GLfloat groundColor[4] = {0.0, 0.5, 0.0, 1.0};   //green[6]
    
        BallColor();
};

#endif /* color_hpp */