/*billiards*/

#include "main.hpp"

bool mouseDown; //@@@1変数の受け渡し
int initStatus; //球初期化用 1.全初期化,2.手球初期化
int debugNum;   //デバック処理
float argNum[2];   //関数間数値受け渡し用

void SetNum(float argOne,float argTwo){
    argNum[0] = argOne;
    argNum[1] = argTwo;
}

void display(void){
    static FpsMonitor fpsMonitor;   //FPS管理
    
    fpsMonitor.drawStart = glutGet(GLUT_ELAPSED_TIME);
    
    /*クラス生成 @@@ */
    static DrawObject draw;
    static GameControl gameControl;
    static BallColor ballColor;
    static Ball ball[10];
    static Pocket pocket[6];
    static PhysicsCalculation physics;
    
    /*光源の位置*/
    static GLfloat  lightpos[] = {0.4,1.0,1.0,0.6};
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    /*光源の位置設定*/
    glLightfv(GL_LIGHT0,GL_POSITION, lightpos);
    
    /*カメラの位置*/
    glTranslated(cameraPos.x, cameraPos.y, -5.0);
    glRotated(45.0, 90.0, 0.0, 0.0);

    /*台の描画*/
    draw.ground(-0.0, ballColor.groundColor);
    
    /*ポケットの描画*/
    for(int i=0;i<6;i++) pocket[i].MakePocket(0.5);
    
    /*球初期化位置*/
    if(initStatus == true){
        for(int i=0; i<BALL_NUM;i++){
            ball[i].InitPos(i);
            ball[i].life = true;
        }
        for(int i=0;i<6;i++){
            pocket[i].InitPos(i);
            pocket[i].MakePocket(0.5);
        }
        initStatus = false;
        gameControl.initFlag = false;
    }
    //手球だけ初期化
    if(initStatus == 2){
        ball[0].InitPos(0);
        ball[0].life = true;
        initStatus = false;
    }
    
    /*手球のショット*/
    if(mouseDown && !gameControl.mouseDown && ball[0].speed.x == 0 && ball[0].speed.z == 0){
        gameControl.mousePos[X] = argNum[0];
        gameControl.mousePos[Y] = argNum[1];
        
        gameControl.mouseDown = true;
    }
    if(!mouseDown && gameControl.mouseDown){
        ball[0].speed.x = (float)((gameControl.mousePos[X] - argNum[0])/1000);
        ball[0].speed.z = (float)((gameControl.mousePos[Y] - argNum[1])/1000);
        
        gameControl.mouseDown = false;
    }
    
    /*球移動処理*/
    glPushMatrix();
    if(debugNum == 1)ball[0].pos.z -= 0.01;
    if(debugNum == 2)ball[0].pos.z += 0.01;
    if(debugNum == 3)ball[0].pos.x -= 0.01;
    if(debugNum == 4)ball[0].pos.x += 0.01;
    glPopMatrix();

    for(int i=0;i<BALL_NUM;i++){
        glPushMatrix();
        if(ball[i].life == false) continue;
        for(int j=0;j<BALL_NUM;j++){
            if(i==j ) break;
         //   if(ball[j].life == false) break;
            
            //反射方向算出
            physics.Refrect(ball[i].pos, ball[j].pos,ball[i].speed,ball[j].speed,BALL_WEIGHT,BALL_WEIGHT);
        }
        
        ball[i].Move(); //位置決定
        ball[i].RefrectWall(ball[i].pos);
        glTranslated(ball[i].pos.x, 0.0, ball[i].pos.z);
        glRotated(10.0, 0.0, 0.0, 0.0);
        ball[i].MakeBall(0.5,ballColor.colorCode[i]);
        
        //ポッケに入っているかチェック
        if(ball[i].pos.x < -TABLE_WIDTH+BALL_RANGE*2 || ball[i].pos.x > TABLE_WIDTH-BALL_RANGE*2){
            if(ball[i].pos.z <-TABLE_DEPTH+BALL_RANGE*2 || ball[i].pos.z >TABLE_DEPTH-BALL_RANGE*2 || ball[i].pos.z < BALL_RANGE && ball[i].pos.z > -BALL_RANGE){
                
                ball[i].speed.x = ball[i].speed.z = 0.0;
                ball[i].pos.x = ball[i].pos.z = 90.0;
                ball[i].life = false;
            }
        }
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
            LeftMoveCamera();
            break;
            
        case 'd':
        case 'D':
            RightMoveCamera();
            break;
            
        case 'w':
        case 'W':
            FrontMoveCamera();
            break;
            
        case 's':
        case 'S':
            BackMoveCamera();
            break;
            
        /*手玉初期化*/
        case 'x':
        case 'X':
            initStatus = 2;
            break;
            
        /*全球初期化*/
        case 'z':
        case 'Z':
            initStatus = true;
            break;
            
        case '_':
            debugNum = 0;
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


void specialKey(int key,int x, int y){
    /*カメラ移動*/
    switch (key) {
        case GLUT_KEY_UP:
            debugNum = 1;
            break;
        case GLUT_KEY_DOWN:
            debugNum = 2;
            break;
        case GLUT_KEY_LEFT:
            debugNum = 3;
            break;
        case GLUT_KEY_RIGHT:
            debugNum = 4;
            break;
        default:
            debugNum = 0;
            break;
    }
}

void mouse(int button, int state, int x, int y){
    switch(button){
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){
                if(!mouseDown)  SetNum(x,y);    //マウス座標保存
                mouseDown = true;
                break;
            }
            else{
                //クリックを話したらfalse
                if(mouseDown){
                    SetNum(x,y);    //マウス座標保存
                    mouseDown=false;
                }
            }
        default:
            break;
    }
}

void init(void)
{
    /*初期設定*/
    debugNum=0;
    initStatus = true;
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
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
    glutMouseFunc(mouse);
    init();
    
    glutMainLoop();
    return 0;
}