//
//  FpsMonitor.hpp
//  OpenGL_Billiards
//
//  Created by Gurigura on 2016/11/16.
//  Copyright © 2016年 Guriguragurarira. All rights reserved.
//

#ifndef FpsMonitor_hpp
#define FpsMonitor_hpp

#include <stdio.h>
#include "define.hpp"

class FpsMonitor{
    
private:
    
public:
    void    initFps();
    double  nowFps;
    double  nowSpf;
    int     frameCounter;
    double  nowTime;
    double  timebase;
    double  drawStart;
    double  drawEnd;
    
};


#endif /* FpsMonitor_hpp */
