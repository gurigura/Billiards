/*色コード管理*/

#ifndef color_hpp
#define color_hpp

#include "Define.hpp"

class BallColor{

    public:
        /*球色コード*/
        GLfloat  colorCode[10][4];
        /*テーブル色コード*/
        GLfloat groundColor[4];   //green[6]
    
        BallColor();
};

#endif /* color_hpp */