/*FPS管理*/

#ifndef FpsMonitor_hpp
#define FpsMonitor_hpp

#include <stdio.h>
#include "define.hpp"

class FpsMonitor{
    
private:
    
public:
    FpsMonitor();
    double  nowFps; //現在FPS
    double  nowSpf; //現在SPF
//   int     frameCounter;
    double  nowTime;    //現在時間
//    double  timebase;   //
    double  drawStart;  //フレーム時間計測開始時刻
    double  drawEnd;    //フレーム時間計測開始時刻
    
};


#endif /* FpsMonitor_hpp */
