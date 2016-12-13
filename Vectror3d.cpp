/*ベクトルクラス
 *
 *注意 * OpneGLUT用にGLdoubleに変更箇所あり
 */

#include "Vectror3d.hpp"

/*コンストラクタ*/
Vector3d::Vector3d(){
        x=y=z=0.0;
}
/*コンストラクタ　引数:x, y, z*/
Vector3d::Vector3d(GLdouble arcx,GLdouble arcy, GLdouble arcz){
    x=arcx;
    y=arcy;
    z=arcz;
}
/*コンストラクタ　引数:*x, *y, *z*/
Vector3d::Vector3d(GLdouble *arcx,GLdouble *arcy, GLdouble *arcz){
    x=*arcx;
    y=*arcy;
    z=*arcz;
}

/*ベクトル正規化*/
Vector3d Vector3d::normalize(){
    GLdouble arcNorm;
    Vector3d argVec;
    arcNorm = sqrt(this->length());
    if(arcNorm == 0){
        argVec.x = 0;
        argVec.y = 0;
        argVec.z = 0;
    }else{
        argVec.x = x / fabs(arcNorm);
        argVec.y = y / fabs(arcNorm);
        argVec.z = z / fabs(arcNorm);
    }
    return argVec;
}

double Vector3d::length(){
    return  x*x + y*y + z*z;
}

double Vector3d::length(Vector3d argVec){
    return  argVec.x*argVec.x + argVec.y*argVec.y + argVec.z*argVec.z;
}

/*内積*/
double dot(Vector3d argVec1,Vector3d argVec2){
    double argDot = argVec1.x*argVec2.x + argVec1.y*argVec2.y + argVec1.z*argVec2.z;
    return argDot;
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
    //分母0　除算   **********************************
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
    w.z = u.z + v.z;
    return w;
}
Vector3d operator-(const Vector3d& u,const Vector3d& v){
    Vector3d w;
    w.x = u.x - v.x;
    w.y = u.y - v.y;
    w.z = u.z - v.z;
    return w;
}

float   operator*(const Vector3d& u,const Vector3d& v){
    return u.x*v.x + u.y*v.y;
}


Vector3d operator*(const Vector3d& v,float k){
    Vector3d w;
    w.x = v.x * k;
    w.y = v.y * k;
    w.z = v.z * k;
    return w;
}

Vector3d operator*(float k, const Vector3d& v){
    Vector3d w;
    w.x = v.x * k;
    w.y = v.y * k;
    w.z = v.z * k;
    return w;
}

Vector3d operator/(const Vector3d& v,float k){
    Vector3d w;
    w.x = v.x / k;
    w.y = v.y / k;
    w.z = v.z / k;
    return w;
}

