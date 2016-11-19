
#include "Vectror3d.hpp"

Vector3d::Vector3d(){
    //    pos[0]=pos[1]=pos[2]=0.0;
        x=y=z=0.0;
}
Vector3d::Vector3d(GLdouble arcx,GLdouble arcy, GLdouble arcz){
    x=arcx;
    y=arcy;
    z=arcz;
}

Vector3d::Vector3d(GLdouble *arcx,GLdouble *arcy, GLdouble *arcz){
    x=*arcx;
    y=*arcy;
    z=*arcz;
}

void Vector3d::normalize(){
    GLdouble arcNorm;
    
    arcNorm = sqrt(x*x+ y*y + z*z);
    x = x / fabs(arcNorm);
    y = y / fabs(arcNorm);
    z = z / fabs(arcNorm);
}

/*代入演算子*/
Vector3d& Vector3d::operator=(const Vector3d& v){
    
    this->x=v.x;
    this->y=v.y;
    this->z=v.z;
    
    return *this;
}

/* += */
Vector3d& Vector3d::operator+=(const Vector3d& v){
    this->x+=v.x;
    this->y+=v.y;
    this->z+=v.z;
    return *this;
}

/* -= */
Vector3d& Vector3d::operator-=(const Vector3d& v){
    this->x-=v.x;
    this->y-=v.y;
    this->z-=v.z;
    return *this;
}

/* *= */
Vector3d& Vector3d::operator*=(float f){
    this->x*=f;
    this->y*=f;
    this->z*=f;
    return *this;
}

/* /= */
Vector3d& Vector3d::operator/=(float f){
    //分母0　除算
    if(f==0){
        std::cout << "warning!!" << std::endl;
        exit(0);
    }
    this->x/=f;
    this->y/=f;
    this->z/=f;
    return *this;
}

/* +の定義 */
Vector3d Vector3d::operator+(){
    return *this;
}

/* -の定義 */
Vector3d Vector3d::operator-(){
    return Vector3d(-x,-y,-z);
}

/*二項演算子*/
Vector3d operator+(const Vector3d& u,const Vector3d& v){
    Vector3d w;
    w.x = u.x + v.x;
    w.y = u.y + v.y;
    return w;
}
Vector3d operator-(const Vector3d& u,const Vector3d& v){
    Vector3d w;
    w.x = u.x - v.x;
    w.y = u.y - v.y;
    return w;
}

float   operator*(const Vector3d& u,const Vector3d& v){
    return u.x*v.x + u.y*v.y;
}


Vector3d operator*(const Vector3d& v,float k){
    Vector3d w;
    w.x = v.x * k;
    w.y = v.y * k;
    return w;
}

Vector3d operator*(float k, const Vector3d& v){
    Vector3d w;
    w.x = v.x * k;
    w.y = v.y * k;
    return w;
}

Vector3d operator/(const Vector3d& v,float k){
    Vector3d w;
    w.x = v.x / k;
    w.y = v.y / k;
    return w;
}




