/*色コード管理*/

#ifndef color_hpp
#define color_hpp

#include "Define.hpp"

class BallColor{

    public:
        /*球色コード*/
        GLfloat  colorCode[10][4];
        /*テーブル色コード*/
        GLfloat groundColor[4] = {0.0, 0.5, 0.0, 1.0};   //green[6]
    
        BallColor();
};

#endif /* color_hpp */