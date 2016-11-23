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
void PhysicsCalculation::Refrect(GLdouble *argPos1, GLdouble *argPos2,  Vector3d &argVec1, Vector3d &argVec2){
   
    
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
        argPos1[X] += bunpX*dis;
        argPos1[Z] += bunpZ*dis;
        argPos2[X] -= bunpX*dis;
        argPos2[Z] -= bunpZ*dis;
        
        double t;
        double firstVec[3],secondVec[3],firstTorque[3],secondTorque[3];
        
        t = -(bunpX*argVec1.x + bunpZ*argVec1.z)/bunpLen;
        firstTorque[X] = argVec1.x + (bunpX * t);
        firstTorque[Y] = 0;
        firstTorque[Z] = argVec1.z + (bunpZ * t);
        
        t = -(-bunpZ*argVec1.x + bunpX*argVec1.z)/bunpLen;
        firstVec[X] = argVec1.x - (bunpZ * t);
        firstVec[Y] = 0;
        firstVec[Z] = argVec1.z + (bunpX * t);
        
        t = -(bunpX*argVec2.x + bunpZ*argVec2.z)/bunpLen;
        secondTorque[X] = argVec2.x - bunpX * t;
        secondTorque[Y] = 0;
        secondTorque[Z] = argVec2.z + bunpZ * t;
        
        t = -(-bunpZ*argVec2.x + bunpX*argVec2.z)/bunpLen;
        secondVec[X] = argVec2.x - bunpZ * t;
        secondVec[Y] = 0;
        secondVec[Z] = argVec2.z + bunpX * t;
        
        argVec1.x = (BALL_WEIGHT*firstVec[X] + BALL_WEIGHT*secondVec[X] + secondVec[X]*BALL_WEIGHT-firstVec[X]*BALL_WEIGHT)/(BALL_WEIGHT+BALL_WEIGHT) + firstTorque[X];//(m*vX1 + m*vX2 + vx2*m-vx1*m*)/m+m
        argVec2.x = -1 * (secondVec[X]-firstVec[X]) + argVec1.x + secondTorque[X];
        argVec1.z = (BALL_WEIGHT*firstVec[Z] + BALL_WEIGHT*secondVec[Z] + secondVec[Z]*BALL_WEIGHT-firstVec[Z]*BALL_WEIGHT)/(BALL_WEIGHT+BALL_WEIGHT) + firstTorque[Z] ;
        argVec2.z = -1 * (secondVec[Z]-firstVec[Z]) + argVec1.z + secondTorque[Z];
        
        argVec1 = argVec1.normalize()*0.05;
        argVec2 = argVec2.normalize()*0.05;
        printf("vecX,VecZ %lf,%lf \n",argVec1.x,argVec1.z);
   //     printf("------- %lf,%lf ------\n",argVec2.x,argVec2.z);
        
        
        
        
        /*法線を取る方法2*/
        /*
        GLdouble argDis[3];
        double forceVec=sqrt(argVec1.x * argVec1.x + argVec1.z * argVec1.z);
        double radian1 = atan2(argPos2[X]-argPos1[X], argPos2[Z]-argPos1[Z]);
        double radian2 = atan2(argVec1.x,argVec1.z);
        double refRadian = radian2 - radian1;
        printf("-------------%lf\n",refRadian);
        double speed_second = fabs(forceVec * sin(refRadian));
        double speed_first = fabs(forceVec * cos(refRadian));
        argVec2.x = speed_second*cos(radian1);
        argVec2.z = speed_second*sin(radian1);
        
        if(sin(refRadian) < 0){
            argVec1.x = speed_first*cos((PI/2) - radian1);
            argVec1.z = speed_first*sin((PI/2) - radian1);
        }else{
            argVec1.x = speed_first*cos((PI/2) + radian1);
            argVec1.z = speed_first*sin((PI/2) + radian1);
        }
        */
    }
  
}


