/*物理演算*/

#ifndef Physics_hpp
#define Physics_hpp

#include "Define.hpp"
#include <math.h>

using namespace std;

class PhysicsCalculation : public Vector3d{
    
public:
    PhysicsCalculation();
    
    Vector3d vector3d;
    
    /*衝突判定 引数:*一つ目の球座標, *一つ目の球座標*/
    bool DistanceXZ(GLdouble *argPos1, GLdouble *argPos2);
    
    /*反射方向 引数:*一つ目の球座標, *二つ目の球座標, 一つ目の球ベクトル, 二つ目の球ベクトル */
    void Refrect(Vector3d &argPos1, Vector3d &argPos2,  Vector3d &speed1, Vector3d &speed2, float weight1, float weight2);
    
    

    
    
};


#endif /* Physics_hpp */
