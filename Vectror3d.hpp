/*ベクトルクラス
 *
 *注意 * OpneGLUT用にGLdoubleに変更箇所あり
 */

#ifndef Vectror3d_hpp
#define Vectror3d_hpp

#include <GLUT/glut.h>
#include <iostream>
#include <math.h>

class Vector3d{
public:
    GLdouble x,y,z;
    Vector3d();
    Vector3d(GLdouble x, GLdouble y, GLdouble z);
    Vector3d(GLdouble *x, GLdouble *y, GLdouble *z);
    Vector3d normalize();   /*正規化*/
    double length();
    double length(Vector3d);    /*長さ*/
    
    /*演算子定義系*/
    /*代入演算子*/
    Vector3d& operator=(const Vector3d& v);
    Vector3d& operator+=(const Vector3d& v);
    Vector3d& operator-=(const Vector3d& v);
    Vector3d& operator*=(float f);
    Vector3d& operator/=(float f);
    Vector3d operator+();
    Vector3d operator-();
    
};

/*二項演算子*/
Vector3d operator+(const Vector3d& u,const Vector3d& v);
Vector3d operator-(const Vector3d& u,const Vector3d& v);

float   operator*(const Vector3d& u,const Vector3d& v);

Vector3d operator*(const Vector3d& v,float k);
Vector3d operator*(float k, const Vector3d& v);
Vector3d operator/(const Vector3d& v,float k);

#endif /* Vectror3d_hpp */
