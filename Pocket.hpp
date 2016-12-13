//
//  Pocket.hpp
//  OpenGL_Billiards
//
//  Created by Gurigura on 2016/12/12.
//  Copyright © 2016年 Guriguragurarira. All rights reserved.
//

#ifndef Pocket_hpp
#define Pocket_hpp

#include "Define.hpp"

class Pocket{
public:
    Vector3d pos;    //座標
    Pocket();
    void MakePocket(double height);
    /*ポケット位置初期化*/
    void InitPos(int ballNumber);
    
private:
    GLfloat color[4];   //black
    /*ポケット初期位置情報*/
    GLfloat initPos[6][3];

};

#endif /* Pocket_hpp */
