/*物理演算*/

#ifndef Physics_hpp
#define Physics_hpp

#include "Define.hpp"

using namespace std;

class PhysicsCalculation : public Vector3d{
private:
    
public:
    PhysicsCalculation();
    
    /*衝突判定 引数:*一つ目の球座標, *一つ目の球座標*/
    bool DistanceXZ(GLdouble *argPos1, GLdouble *argPos2);
    
    /*反射方向 引数:*一つ目の球座標, *二つ目の球座標, 一つ目の球ベクトル, 二つ目の球ベクトル */
    void Refrect(GLdouble *argPos1, GLdouble *argPos2,  Vector3d &speed1, Vector3d &speed2);
    

    
    
};


#endif /* Physics_hpp */
