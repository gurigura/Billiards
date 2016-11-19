/*
 * 固定オブジェクト描画クラス
 *  
 */

#include "Draw.hpp"



/*コンストラクタ*/
DrawObject::DrawObject(){
    
}

/*テーブルの描画*/
void DrawObject::ground(double height,GLfloat* color){
    GLfloat colorGround[4] = {0.0,0.5,0.0,1.0};      //static or メンバ？
    
    /*床を描く*/
//    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glNormal3b(0.0,0.0,1.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
    glVertex3d(-TABLE_WIDTH,height,-TABLE_DEPTH);
    glVertex3d(-TABLE_WIDTH,height,TABLE_DEPTH);
    glVertex3d(TABLE_WIDTH,height,TABLE_DEPTH);
    glVertex3d(TABLE_WIDTH,height,-TABLE_DEPTH);
    
  glEnd();
  //  glFlush();
}