/*billiards*/


#include "main.hpp"


bool mouseDown; //@@@1変数の受け渡し


void display(void){
    
    static FpsMonitor fpsMonitor;   //FPS管理
    
    fpsMonitor.drawStart = glutGet(GLUT_ELAPSED_TIME);
    
    /*クラス生成 @@@ */
    static DrawObject draw;
    static GameControl gameControl;
    static BallColor ballColor;
    static Ball ball[10];
    static PhysicsCalculation physics;
    
    /*光源の位置*/
    static GLfloat  lightpos[] = {1.0,1.0,1.0,1.0};
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    /*光源の位置設定*/
    glLightfv(GL_LIGHT0,GL_POSITION, lightpos);
    
    /*カメラの位置*/
    glTranslated(cameraPos[0], cameraPos[1], cameraPos[2]);
    glRotated(45.0, 90.0, 0.0, 0.0);

    /*描画クラスの反映をここに！！！*/
    draw.ground(0.0,ballColor.groundColor);
    
    /*球初期化位置*/
    if(gameControl.initFlag == true){
        for(int i=0; i<BALL_NUM;i++)    ball[i].InitPos(i);
        gameControl.initFlag = false;
    }
    
    /*手球のショット*/
    if(mouseDown) {
        ball[0].pow-=0.001;
    }else if(ball[0].pow != 0){
        ball[0].z = ball[0].pow;
        ball[0].x = ball[0].pow;
        ball[0].pow = 0;
    }
    
    
    /*球移動処理*/
    for(int i=0;i<BALL_NUM;i++){
        glPushMatrix();
        for(int j=0;j<BALL_NUM;j++){
            if(i<=j ) break;
            //反射方向算出
            physics.Refrect(ball[i].pos, ball[j].pos,ball[i],ball[j]);
        }
        ball[i].Move(); //位置決定
        ball[i].RefrectWall(ball[i].pos);
        
        glTranslated(ball[i].pos[X], 0.0, ball[i].pos[Z]);
        ball[i].MakeBall(0.5,ballColor.colorCode[i]);
        glPopMatrix();
    }
    
    glutSwapBuffers();
    glutPostRedisplay();
    
    fpsMonitor.drawEnd = glutGet(GLUT_ELAPSED_TIME);
   //  printf("second per frame %f second \r",(fpsMonitor.drawEnd - fpsMonitor.drawStart)/1000.0);
    
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
    
    /*カメラ移動*/
    switch (key) {
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
                //クリックを話したらfalse
                if(mouseDown)mouseDown=false;
            }
    }
    
}

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