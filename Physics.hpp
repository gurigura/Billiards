
#ifndef Physics_hpp
#define Physics_hpp

#include "Define.hpp"

using namespace std;

class PhysicsCalculation : public Vector3d{
private:
    
public:
    PhysicsCalculation();
    
    /*衝突判定 引数第一:*GLdouble_pos1[], 第二:*GLdouble_pos2[]*/
    bool DistanceXZ(GLdouble *argPos1, GLdouble *argPos2);
    
    
    /*エラーにつき一時的に第三第四引数変更*/
    /*反射方向 引数第一:*GLdouble_pos1[], 第二:*GLdouble_pos2[], 第三:Vec_vec1, 第四:Vec_vec2 */
    void Refrect(GLdouble *argPos1, GLdouble *argPos2,  Vector3d argVec1, Vector3d argVec2);
    
    
    
    
};


#endif /* Physics_hpp */
