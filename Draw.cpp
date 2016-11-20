/*
 * 固定オブジェクト描画クラス
 */

#include "Draw.hpp"

DrawObject::DrawObject(){
    
}

/*テーブルの描画 引数:高さ,色*/
void DrawObject::ground(double height,GLfloat* color){
  //  GLdouble colorGround[4] = {0.0,0.5,0.0,1.0};      //static or メンバ？
    
    /*床を描く*/
//    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_QUADS);
  //  glNormal3b(0.0,1.0,0.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
  //  glColor3f(0.0,1.0,0.0);
    glVertex3d(-TABLE_WIDTH,height,-TABLE_DEPTH-0.6);
    glVertex3d(-TABLE_WIDTH,height,TABLE_DEPTH-0.6);
    glVertex3d(TABLE_WIDTH,height,TABLE_DEPTH-0.6);
    glVertex3d(TABLE_WIDTH,height,-TABLE_DEPTH-0.6);
    
  glEnd();
}