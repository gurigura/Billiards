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

/*球同士の反射 first=引数前者,second=引数後者
 *引数1,2:球座標1と2, 3,4:球速度1と2, 5,6:球重量1と2
 */
void PhysicsCalculation::Refrect(Vector3d &argPos1, Vector3d &argPos2,  Vector3d &speed1, Vector3d &speed2, float weight1, float weight2){
    ///計算式３

    if((argPos2.x-argPos1.x)*(argPos2.x-argPos1.x) + (argPos2.z-argPos1.z)*(argPos2.z-argPos1.z) <= BALL_RANGE*BALL_RANGE+0.008){
        
        float totalWeight = weight1 + weight2;
        float refRate = 1;
        Vector3d nom = argPos2 - argPos1;
        nom = nom.normalize();
        Vector3d argVec = speed2-speed1;
        double argDot = argVec.x*nom.x + argVec.y*nom.y + argVec.z*nom.z;
        argVec = (refRate*argDot/totalWeight)*nom;
        speed2 += -weight2 * argVec ;
        speed1 += weight1 * argVec ;
        
        /*めり込みを戻す*/
        double bunpX = argPos1.x-argPos2.x;   //Xの２距離間
        double bunpZ = argPos1.z-argPos2.z;   //Zの２距離間
        double bunpLen = bunpX*bunpX + bunpZ*bunpZ;
        double len = sqrt(bunpLen);
        double dis = (BALL_RANGE+BALL_RANGE) - len; //めり込み量
        
        bunpX = bunpX/len;
        bunpZ = bunpZ/len;

        dis /= 2.0; //半分ずつ移動の為の/2

        argPos1.x += bunpX*dis;
        argPos2.x -= bunpX*dis;

        argPos1.z += bunpZ*dis;
        argPos2.z -= bunpZ*dis;
     
        cout << "check" << endl;
    }
}
