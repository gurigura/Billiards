
#include "main.hpp"


bool mouseDown; //@@@1変数の受け渡し


void display(void){
    
    static FpsMonitor fpsMonitor;
    
    
    fpsMonitor.drawStart = glutGet(GLUT_ELAPSED_TIME);
    
    /*クラス生成 @@@ */
    static DrawObject draw;
    static GameControl gameControl;
    static BallColor ballColor;
    static Ball ball[10];
    static PhysicsCalculation physics;
    
    /*光源の位置*/
    static GLfloat  lightpos[] = {1.0,2.0,3.0,1.0};
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    
    /*光源の位置設定*/
    glLightfv(GL_LIGHT0,GL_POSITION, lightpos);
    
    /*カメラの位置*/
    glTranslated(cameraPos[0], cameraPos[1], cameraPos[2]);
    glRotated(45.0, 90.0, 0.0, 0.0);

    
    /*描画クラスの反映をここに！！！*/
    draw.ground(0.1,ballColor.groundColor);

    /*描画ここまで*/
    
    /*球初期化位置*/
    if(gameControl.initFlag == true){
        for(int i=0; i<BALL_NUM;i++)    ball[i].InitPos(i);
        gameControl.initFlag = false;
    }
    
    /*手球の貯め*/
    if(mouseDown) {
        ball[0].pow-=0.001;
    }else if(ball[0].pow != 0){
        ball[0].speed = ball[0].pow;
        ball[0].pow = 0;
    }
    
    
    /*球移動処理*/
    for(int i=0;i<BALL_NUM;i++){
        glPushMatrix();
        for(int j=0;j<BALL_NUM;j++){
            if(i==j) break;

            physics.Refrect(ball[i].pos, ball[j].pos,ball[i].setVec(),ball[j].setVec());
            
        
        }
        ball[i].RefrectWall();
        ball[i].Move();
   
        
        glTranslated(ball[i].pos[0], 0.0, ball[i].pos[2]);
        ball[i].MakeBall(0.5,ballColor.colorCode[i]);
        glPopMatrix();
    }
    
    glutSwapBuffers();
    glutPostRedisplay();
    
    fpsMonitor.drawEnd = glutGet(GLUT_ELAPSED_TIME);
     printf("second per frame %f second \r",(fpsMonitor.drawEnd - fpsMonitor.drawStart)/1000.0);
    
}

void resize(int w, int h){
    //ウィンドウ全体をビューポートにする
    glViewport(0,0,w,h);
    
    /*投資変換行列の初期*/
    glMatrixMode(GL_PROJECTION);
    
    /*モデルビュー変換行列の指定*/
    glLoadIdentity();
    gluPerspective(30.0,(double)w / (double)h,1.0,100.0);
    
    /*モデルビュー変換行列の指定*/
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key,int x, int y){
    
    switch (key) {
        /*カメラ移動*/
            
        case 'a':
        case 'A':
            glutIdleFunc(LeftMoveCamera);
     //       glutPostRedisplay();
            break;
            
        case 'd':
        case 'D':
            glutIdleFunc(RightMoveCamera);
   //         glutPostRedisplay();
            break;
            
        case 'w':
        case 'W':
            glutIdleFunc(FrontMoveCamera);
    //        glutPostRedisplay();
            break;
            
        case 's':
        case 'S':
            glutIdleFunc(BackMoveCamera);
     //       glutPostRedisplay();
            break;
            
    
        /*終了処理*/
        case '\033':
        case 'q':
            exit(0);
            break;
            
        default:
            break;
    }
}

void mouse(int button, int state, int x, int y){
    switch(button){
        case GLUT_LEFT_BUTTON:
            /*マウスをクリックしたウィンドウ上の座標から
             表示されている台の表面の空間位置を求める*/
            if(state == GLUT_DOWN){
                mouseDown = true;
                break;
            case GLUT_MIDDLE_BUTTON:
                break;
            case GLUT_RIGHT_BUTTON:
                break;
            default:
                break;
            }
            else{
                /*クリックを話したらフラグファルス*/
                if(mouseDown)mouseDown=false;
            }
            /*else{
             glutIdleFunc(0);
             }*/
    }
    
}

/*画面再描画*/
/*
void Idle(){
    glutPostRedisplay();
}
 */

void init(void)
{
    /*初期設定*/
    mouseDown = false;
    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

int main(int argc, char *argv[]){
    printf("%f\n",TABLE_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(760,600);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
//    glutIdleFunc(Idle);
    init();
    
    glutMainLoop();
    return 0;
}