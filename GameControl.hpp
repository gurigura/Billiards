/*ゲームコントローラー*/

#ifndef GameControl_hpp
#define GameControl_hpp

#include "Define.hpp"

class GameControl{
    
public:
    GameControl();
    bool initFlag;  //初期化フラグ
    bool mouseDown; //クリックフラグ
    int mousePos[2]; //マウス位置
    
};

#endif /* GameControl_hpp */
