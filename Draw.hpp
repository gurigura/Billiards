/*
 * 固定オブジェクト描画クラス
 */

#ifndef draw_hpp
#define draw_hpp

#include <GLUT/glut.h>
#include "Define.hpp"

class DrawObject{
    public:
    DrawObject();
    
    /*テーブルの描画 引数:高さ,色*/
    void ground(double height);
    
};

#endif /* draw_hpp */
