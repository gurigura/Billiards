/*ボール挙動管理*/

#ifndef Ball_hpp
#define Ball_hpp

#include "Define.hpp"

class Ball{
    public:
        Ball();
    
        Vector3d speed;
        bool initFlag;  //初期化フラグ
        bool life;
        Vector3d pos;    //座標
        GLdouble pow; //ショットの強さ
    
        /*ボール描画*/
        void    MakeBall(double height, GLfloat color[]);
        /*ボール位置初期化*/
        void    InitPos(int ballNumber);
        /*ボール移動(座標変更)*/
        void    Move();
        /*ボールと壁の反射*/
        void    RefrectWall(Vector3d &argPos);
        //ベクトルreturn
        Vector3d getVec();
    
    private:
        /*ボール初期位置情報*/
        GLfloat initPos[BALL_NUM][3];
};

#endif /* Ball_hpp */
