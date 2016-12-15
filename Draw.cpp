/*
 * 固定オブジェクト描画クラス
 */

#include "Draw.hpp"

DrawObject::DrawObject(){
    
}

/*テーブルの描画 引数:高さ,色*/
void DrawObject::ground(double height){
    GLfloat colorPool[4] = {0.0,0.5,0.0,1.0};
    GLfloat colorWall[4] = {0.5,0.0,0.0,0.7};
    
    /*床を描く*/
    
    //プールの描画
    glBegin(GL_QUADS);
    glNormal3f(0.0,1.0,0.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorPool);
    glColor3f(0.0,1.0,0.0);
    glVertex3d(-TABLE_WIDTH-0.1,height,-TABLE_DEPTH-0.8);
    glVertex3d(-TABLE_WIDTH-0.1,height, TABLE_DEPTH-0.3);
    glVertex3d( TABLE_WIDTH+0.1,height, TABLE_DEPTH-0.3);
    glVertex3d( TABLE_WIDTH+0.1,height,-TABLE_DEPTH-0.8);
    glEnd();
    
    glBegin(GL_QUADS);
    glNormal3f(0.0,1.0,0.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorWall);
    glColor3f(0.0,1.0,0.0);
    glVertex3d(-TABLE_WIDTH-0.2,height-0.00001,-TABLE_DEPTH-0.9);
    glVertex3d(-TABLE_WIDTH-0.2,height-0.00001, TABLE_DEPTH-0.2);
    glVertex3d( TABLE_WIDTH+0.2,height-0.00001, TABLE_DEPTH-0.2);
    glVertex3d( TABLE_WIDTH+0.2,height-0.00001,-TABLE_DEPTH-0.9);
    
    glEnd();

}