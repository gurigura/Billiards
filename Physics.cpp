/*物理演算*/

#include "Physics.hpp"

PhysicsCalculation::PhysicsCalculation(){
    
}

/*現在未使用・検証用・反射方向＆量計算　引数:一つ目の球座標,二つ目の球座標*/
bool PhysicsCalculation::DistanceXZ(GLdouble *argPos1,GLdouble *argPos2){
    bool flag = false;
    if( fabs(argPos1[0]-argPos2[0]) < BALL_RANGE*1.81 && fabs(argPos1[2] - argPos2[2]) < BALL_RANGE*1.8){
        printf("hit");
        flag = true;
    }
    return flag;
}

/*球同士の反射 first=引数前者,second=引数後者*/
void PhysicsCalculation::Refrect(GLdouble *argPos1, GLdouble *argPos2,  Vector3d &speed1, Vector3d &speed2){
   
    
    if((argPos2[X]-argPos1[X])*(argPos2[X]-argPos1[X]) + (argPos2[Z]-argPos1[Z])*(argPos2[Z]-argPos1[Z]) < BALL_RANGE*BALL_RANGE){

        /*めり込みを戻す*/
        double bunpX = argPos1[X]-argPos2[X];   //Xの２距離間
        double bunpZ = argPos1[Z]-argPos2[Z];   //Zの２距離間
        double bunpLen = bunpX*bunpX + bunpZ*bunpZ;
        double len = sqrt(bunpLen);
        double dis = (BALL_RANGE+BALL_RANGE) - len; //めり込み量
        if (len>0) len=1/len;

        bunpX *= len;
        bunpZ *= len;
        dis /= 2.0; //半分ずつ移動の為の/2
        if(argPos1[X]>argPos2[X]){
            argPos1[X] += bunpX*dis;
            argPos2[X] -= bunpX*dis;
        }else{
            argPos1[X] -= bunpX*dis;
            argPos2[X] += bunpX*dis;
        }
        if(argPos1[Z]>argPos2[Z]){
            argPos1[Z] += bunpZ*dis;
            argPos2[Z] -= bunpZ*dis;
        }else{
            argPos1[Z] -= bunpZ*dis;
            argPos2[Z] += bunpZ*dis;
        }
        ///計算式３
        float theta1 = atan2(speed1.z,speed1.x);
        
        
        //めり込み量で算出
        double t;
        double firstspeed[3],secondspeed[3],firstTorque[3],secondTorque[3];
        
        t = -(bunpX*speed1.x + bunpZ*speed1.z)/bunpLen;
        firstTorque[X] = speed1.x + (bunpX * t);
        firstTorque[Y] = 0;
        firstTorque[Z] = speed1.z + (bunpZ * t);
        
        t = -(-bunpZ*speed1.x + bunpX*speed1.z)/bunpLen;
        firstspeed[X] = speed1.x - (bunpZ * t);
        firstspeed[Y] = 0;
        firstspeed[Z] = speed1.z + (bunpX * t);
        
        t = -(bunpX*speed2.x + bunpZ*speed2.z)/bunpLen;
        secondTorque[X] = speed2.x - bunpX * t;
        secondTorque[Y] = 0;
        secondTorque[Z] = speed2.z + bunpZ * t;
        
        t = -(-bunpZ*speed2.x + bunpX*speed2.z)/bunpLen;
        secondspeed[X] = speed2.x - bunpZ * t;
        secondspeed[Y] = 0;
        secondspeed[Z] = speed2.z + bunpX * t;
        
        speed1.x = (BALL_WEIGHT*firstspeed[X] + BALL_WEIGHT*secondspeed[X] + secondspeed[X]*BALL_WEIGHT-firstspeed[X]*BALL_WEIGHT)/(BALL_WEIGHT+BALL_WEIGHT) + firstTorque[X];//(m*vX1 + m*vX2 + vx2*m-vx1*m*)/m+m
        speed2.x = -1 * (secondspeed[X]-firstspeed[X]) + speed1.x + secondTorque[X];
        speed1.z = (BALL_WEIGHT*firstspeed[Z] + BALL_WEIGHT*secondspeed[Z] + secondspeed[Z]*BALL_WEIGHT-firstspeed[Z]*BALL_WEIGHT)/(BALL_WEIGHT+BALL_WEIGHT) + firstTorque[Z] ;
        speed2.z = -1 * (secondspeed[Z]-firstspeed[Z]) + speed1.z + secondTorque[Z];
        
        speed1 = speed1.normalize()*0.05;
        speed2 = speed2.normalize()*0.05;
        printf("speedX,speedZ %lf,%lf \n",speed1.x,speed1.z);
        
        
   //     printf("------- %lf,%lf ------\n",speed2.x,speed2.z);
        /*法線を取る方法2*/
        /*
        GLdouble argDis[3];
        double forcespeed=sqrt(speed1.x * speed1.x + speed1.z * speed1.z);
        double radian1 = atan2(argPos2[X]-argPos1[X], argPos2[Z]-argPos1[Z]);
        double radian2 = atan2(speed1.x,speed1.z);
        double refRadian = radian2 - radian1;
        printf("-------------%lf\n",refRadian);
        double speed_second = fabs(forcespeed * sin(refRadian));
        double speed_first = fabs(forcespeed * cos(refRadian));
        speed2.x = speed_second*cos(radian1);
        speed2.z = speed_second*sin(radian1);
        
        if(sin(refRadian) < 0){
            speed1.x = speed_first*cos((PI/2) - radian1);
            speed1.z = speed_first*sin((PI/2) - radian1);
        }else{
            speed1.x = speed_first*cos((PI/2) + radian1);
            speed1.z = speed_first*sin((PI/2) + radian1);
        }
        */
        
        
        
    }
  
}


