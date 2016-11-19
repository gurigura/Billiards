
#ifndef Ball_hpp
#define Ball_hpp

#include "Define.hpp"

class Ball : public Vector3d{
    private:
    /*ボール初期位置情報*/
    GLfloat initPos[BALL_NUM][3] = {
        {0,0, TABLE_DEPTH/2}, //0
        {0,0, -TABLE_DEPTH/2}, //1
        {-BALL_RANGE,0, -TABLE_DEPTH/2 + BALL_RANGE*2},  //2
        { BALL_RANGE,0, -TABLE_DEPTH/2 + BALL_RANGE*2},    //3
        {-BALL_RANGE*2,0, -TABLE_DEPTH/2 + BALL_RANGE*4},  //4
        { BALL_RANGE*2,0, -TABLE_DEPTH/2 + BALL_RANGE*4},  //5
        {-BALL_RANGE,0, -TABLE_DEPTH/2 + BALL_RANGE*6},  //6
        { BALL_RANGE,0, -TABLE_DEPTH/2 + BALL_RANGE*6},   //7
        {0,0, -TABLE_DEPTH/2 + BALL_RANGE*8},   //8
        {0,0, -TABLE_DEPTH/2 + BALL_RANGE*4}   //9
    };
    
    
    public:
        Ball();

        bool initFlag;
        GLdouble pos[3];
        GLdouble speed,pow;
    
        Vector3d setVec();
    
        /*ボール描画*/
        void    MakeBall(double height, GLfloat color[]);
        /*ボール位置初期化*/
        void    InitPos(int ballNumber);
    
        /*ボール移動(座標変更)*/
        void    Move();
    
        /*ボールと壁の反射*/
        void    RefrectWall();
};

#endif /* Ball_hpp */
