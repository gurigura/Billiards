/*FPS管理*/

#include "FpsMonitor.hpp"

FpsMonitor::FpsMonitor(){
    nowFps = 0;
    nowSpf = 0.0;
//    frameCounter = 0.0;
    nowTime = 0.0;
//    timebase = 0.0;
    drawStart = 0.0;
    drawEnd = 0.0;
}
