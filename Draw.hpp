/*
 * 固定オブジェクト描画クラス
 *
 */

#ifndef draw_hpp
#define draw_hpp

#include <GLUT/glut.h>
#include "Define.hpp"

class DrawObject{
    private:
    
    public:
    DrawObject();
    
    void ground(double height,GLfloat* color);
    
};

#endif /* draw_hpp */
