/*物理演算*/

#include "Physics.hpp"

PhysicsCalculation::PhysicsCalculation(){
    
}

/*反射方向＆量計算　引数:一つ目の球座標,二つ目の球座標*/
bool PhysicsCalculation::DistanceXZ(GLdouble *argPos1,GLdouble *argPos2){
    bool flag = false;
    if( fabs(argPos1[0]-argPos2[0]) < BALL_RANGE*1.81 && fabs(argPos1[2] - argPos2[2]) < BALL_RANGE*1.8){
        printf("hit");
        flag = true;
    
    }
    return flag;
}

void PhysicsCalculation::Refrect(GLdouble *argPos1, GLdouble *argPos2,  Vector3d &argVec1, Vector3d &argVec2){
   
    
    if((argPos2[X]-argPos1[X])*(argPos2[X]-argPos1[X]) + (argPos2[Z]-argPos1[Z])*(argPos2[Z]-argPos1[Z]) < BALL_RANGE*BALL_RANGE){
        
        
        GLdouble argDis[3];
        /*めり込みを戻す*/
        
        argDis[X] = ((BALL_RANGE+BALL_RANGE) - fabs(argPos2[X]-argPos1[X]));
    //    argDis[Y] = ((BALL_RANGE+BALL_RANGE) - fabs(argPos2[Y]-argPos1[Y]));
        argDis[Z] = ((BALL_RANGE+BALL_RANGE) - fabs(argPos2[Z]-argPos1[Z]));
        //X軸
        if(argPos1[X] < argPos2[X]){
            argPos1[X] += argDis[X]/2;
            argPos2[X] -= argDis[X]/2;
        }else if (argPos2 < argPos1){
            argPos2[X] += argDis[X]/2;
            argPos1[X] -= argDis[X]/2;
        }
        //Y軸
        /*
        if(argPos1[Y] > argPos2[Y]){
            argPos1[Y] += argDis[Y]/2;
            argPos2[Y] -= argDis[Y]/2;
        }else if (argPos2 > argPos1){
            argPos2[Y] += argDis[Y]/2;
            argPos1[Y] -= argDis[Y]/2;
        }
         */
        //Z軸
        if(argPos1[Z] < argPos2[Z]){
            argPos1[Z] += argDis[Z]/2;
            argPos2[Z] -= argDis[Z]/2;
        }else if (argPos2 < argPos1){
            argPos2[Z] += argDis[Z]/2;
            argPos1[Z] -= argDis[Z]/2;
        }
        
        
        
        /*反射方向算出 first=引数前者,second=引数後者*/
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
        
        
        /*
        double radian1 = atan2(argVec1.z ,argVec1.x);
        double radian2 = atan2(argPos1[Z]-argPos2[Z], argPos1[X]-argPos2[X]);
       
        
        
        double refrectRadian = radian1 - radian2;
         printf("%lf\n",refrectRadian);
        argVec1 = argVec1 * sin(refrectRadian);
        argVec2 = argVec1 * cos(refrectRadian);
        
 //       argVec1 = argVec1.normalize();
   //     argVec2 = argVec2.normalize();

        
        printf("%lf, %lf, %lf\n",argVec1.x,argVec1.y,argVec1.z);
        printf("%lf, %lf, %lf\n",argVec2.x,argVec2.y,argVec2.z);
        
        
   /*
        ref[Y] = (((BALL_RANGE+BALL_RANGE) - fabs(argPos1[Y]-argPos2[Y])) / 2) * argVec1.y;
        ref[Z] = (((BALL_RANGE+BALL_RANGE) - fabs(argPos1[Z]-argPos2[Z])) / 2) * argVec1.z;
 
        argVec1.x = ref[X];
        argVec1.y = ref[Y];
        argVec1.z = ref[Z];
        
     */
        
    }
  
}


