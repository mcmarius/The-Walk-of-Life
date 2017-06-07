/**
    The Walk of Life - OpenGL 3D Project
        * Micluta - Campeanu Marius
        * Perescu Antonela-Madalina
        * Merfu Andrei
        * Grupa 252

 */


#include <GL/glew.h>
#include <GL/freeglut.h>
#include <cmath>
#include <ctime>

#include "Models/Player.h"
#include "Views/GroundView.h"
#include "Views/HomeView.h"
//#include "Views/MiscView.h"
//#include "Views/ObstacleView.h"
#include "Views/PlayerView.h"
#include "Views/SkyView.h"
#include "Views/WallView.h"
#include "GameLogic.h"
#include "Views/WeatherView.h"

#include "Views/CollisionBoxView.h"
#include "Views/WineryView.h"
#include "Views/ForestView.h"
#include "Views/BottleView.h"
#include "Utility/Shadows.h"

#include "Utility/BezierSurface.h"

GLint winWidth = 1280, winHeight = 720;

extern GLuint faceTexture;
extern GLuint backSideTexture;
extern GLuint rightSideTexture;
extern GLuint leftSideTexture;
extern GLuint chestTexture;
extern GLuint bellyTexture;

static GLint fogMode;

GLfloat ambient [ ] = {0, 0, 0, 1.0};
double angle, yAngle, beta, balanceSpeed = 0.02;
double lx, ly, lz = -1;
double x = 48.744983, y = 0.5, z = 78.729899;
bool ploaie = false;
bool fog = false;
bool balanceToRight, balanceEnabled, shadowsEnabled;
int limit = 1;
int window;
int valueMenu,returnMenu;
double argument = 0.1;

double alcohol_level = 1000.0;


const double PI = 3.1415926535, halfPI = PI / 2.;//, doublePI = 2 * PI;

std::list<struct Polygon> polygonList(0);

bool initialisedCollisions;

void initialise();
void reshape(int width, int height);
void processNormalKeys(unsigned char key, int, int);
void processSpecialKeys(int key, int, int);
void draw();

void menu(int);
void createMenu();

void computeBalance();

void menu(int n){
    if(n == 0){
        glutDestroyWindow(window);
        exit(0);
    }else{ valueMenu = n ; }
    glutPostRedisplay();
}

void createMenu(){
    returnMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Intro" ,1);
    glutAddMenuEntry("Demo", 2);
    glutAddMenuEntry("Play" ,3);
    glutAddMenuEntry("Quit" ,0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void initialise() {

    srand(time(NULL));

    initialize_trans_x_y();

    // load all textures
    loadGrassTexture();
    loadPathTexture();
    loadTextureOfHouse();
    loadSkyTexture();
    loadStickMaterial();
    loadPlayerTexture("Textures/Player/face.png", faceTexture);
    loadPlayerTexture("Textures/Player/backhead.png", backSideTexture);
    loadPlayerTexture("Textures/Player/right_ear.bmp", rightSideTexture);
    loadPlayerTexture("Textures/Player/left_ear.bmp", leftSideTexture);
    loadPlayerTexture("Textures/Player/chest.png",chestTexture);
    loadPlayerTexture("Textures/Player/belly.png",bellyTexture);

    glEnable(GL_FOG);
    {
        GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};

        fogMode = GL_EXP;
        glFogi (GL_FOG_MODE, fogMode);
        glFogfv (GL_FOG_COLOR, fogColor);
        glFogf (GL_FOG_DENSITY, 0.09);
        glHint (GL_FOG_HINT, GL_DONT_CARE);
        glFogf (GL_FOG_START, 0.0);
        glFogf (GL_FOG_END, 5.0 );

    }
    glClearColor(0.5, 0.5, 0.5, 1.0);  /* fog color */

    initWeather();
    generateBottles();
    initShadowMatrices();
    initBezierGroundSurface();
}

void reshape(int w, int h) {
    winWidth = w;
    winHeight = h;
    if(h == 0)      // Prevent a divide by zero, when window is too short
        h = 1;      // (you cant make a window of zero width).
    double ratio = w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);                // Use the Projection Matrix
    glLoadIdentity();                           // Reset Matrix
    glViewport(0, 0, w, h);                     // Set the viewport to be the entire window
    gluPerspective(45.0, ratio, 0.1, 500.0);    // Set the correct perspective.
    glMatrixMode(GL_MODELVIEW);                 // Get Back to the ModelView
}

void processNormalKeys(unsigned char key, int /*x*/, int /*y*/) {
    double newX;
    double newZ;
    switch(key) {
        case 'd' :
            angle += 0.05;
            newX = sin(angle);
            newZ = -cos(angle);
            if(!anyCollisions(x + newX, z + newZ)) {
                lx = newX;
                lz = newZ;
            }
            else {
                angle -= 0.05;
            }
            break;
        case 'a' :
            angle -= 0.05;
            newX = sin(angle);
            newZ = -cos(angle);
            if(!anyCollisions(x + newX, z + newZ)) {
                lx = newX;
                lz = newZ;
            }
            else {
                angle += 0.05;
            }
            break;
        case 'w' :
            if(yAngle >= halfPI) {
                //yAngle = halfPI;
                ly += 0.01;
            }
            else {
                yAngle += 0.1;
                ly = sin(yAngle);
            }
            break;
        case 's' :
            if(yAngle <= -halfPI) {
                //yAngle = -halfPI;
                ly -= 0.01;
            }
            else {
                yAngle -= 0.1;
                ly = sin(yAngle);
            }
            break;
        case ' ' :
            if(y < 0.51)     // prevent multiple jumps
                y += 0.5;
            break;
        case '0' :
            glDisable(GL_LIGHTING);
            break;
        case '1' :
            glEnable(GL_LIGHTING);
            break;
        case 'p':
            ploaie = !ploaie;
            break;
        case 'l':
            if(alcohol_level <= 1200)
                alcohol_level += 0.6;
            break;

        case 'c':
            printf("%f %f %f\n", x + lx,y + ly , z + lz);
            break;
        case 'f':
        {
            fog = !fog;

        }
        break;
        case 'i':
            y+=50;
            break;
        case ';':
            z+=5;
            break;
        case 'j':
            z-=5;
            break;
        case 'y':
            x+=5;
            break;
        case 'h':
            x-=5;
            break;
        case 'k':
            y-=50;
            break;
        case 'o':
            shadowsEnabled = !shadowsEnabled;
            break;
        case 'b':
            balanceEnabled = !balanceEnabled;
        default:
            break;
    }
    if(key == 27)
        exit(0);
}

void processSpecialKeys(int key, int /*xx*/, int /*yy*/) {

    double fraction = 0.1;
    double newX = sin(angle + halfPI) * fraction;
    double newZ = cos(angle + halfPI) * fraction;
    double newX2 = lx * fraction;
    double newZ2 = lz * fraction;

    switch(key) {
        case GLUT_KEY_LEFT :
            if(!anyCollisions(x + lx - newX, z + lz + newZ)) {
                x -= newX;
                z += newZ;
            }
            break;
        case GLUT_KEY_RIGHT :
            if(!anyCollisions(x + lx + newX, z + lz - newZ)) {
                x += newX;
                z -= newZ;
            }
            break;
        case GLUT_KEY_UP :
            if(!anyCollisions(x + lx + newX2, z + lz + newZ2)) {
                x += newX2;
                z += newZ2;
            }
            break;
        case GLUT_KEY_DOWN :
            if(!anyCollisions(x + lx - newX2, z + lz - newZ2)) {
                x -= newX2;
                z -= newZ2;
            }
            break;
        default:
            break;
    }
}

void draw() {

    if(y > 0.5 ) {
        y -= 2e-2;
    }
    else if(y <= 0.5) {
        y = 0.5;
    }

    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if(balanceEnabled) {
        computeBalance();
        glRotated(beta, 0, 0, 1);       // rotate scene according to the alcohol level
    }

    gluLookAt(x, y + 0.25, z,
              x + lx, y + ly + 0.25, z + lz,
              0.0, 0.75, 0.0);


    skybox();
    drawGround();
    glPushMatrix();
    glPopMatrix();
    drawAHome();
    drawAnotherHome();

    drawPlayer();
    if(shadowsEnabled)
        drawShadows();

    drawFence();
    if(ploaie)
        drawRain();
    drawAForest();
    drawBottles();

    if(alcohol_level > 1050 && alcohol_level < 1150){
        limit = 7;
        balanceSpeed = 0.3;
        argument = 0.15;
    }
    if(alcohol_level > 1150 && alcohol_level < 1250){
        limit = 10;
        balanceSpeed = 0.4;
        argument = 0.17;
    }
    if(alcohol_level > 1250){
        limit = 17;
        balanceSpeed = 0.5;
        argument = 0.2;
    }


    if(fog){
        glEnable(GL_FOG);
        glClearColor(0.5, 0.5, 0.5, 1.0);
    }else if(!fog){
        glDisable(GL_FOG);
    }

    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 3; ++j) {
            displayBezierGroundSurface(3 * i, 2 * j);
        }
    }

  //  drawCollisionBoxes();
    drawWineryBar();

    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();
}

void computeBalance() {
    if(balanceToRight && beta < limit) {
        beta += balanceSpeed;
        if(beta >= limit) {
            balanceToRight = false;
            x += argument;
            z -= argument;
        }
    }
    else if(! balanceToRight && beta > -limit) {
        beta -= balanceSpeed;
        if(beta <= -limit) {
            balanceToRight = true;
            x -= argument;
            z += argument;
        }
    }
}

int main(int argc, char **argv) {
    Player player;      // just to avoid warnings
    player.collectPrize();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(winWidth, winHeight);
    window = glutCreateWindow("The Walk of Life");

    initialise();

    createMenu();

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutIdleFunc(draw);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

  //  glutFullScreen();

    glEnable(GL_DEPTH_TEST);    // OpenGL init
    glutMainLoop();    // enter GLUT event processing cycle
    return 0;
}
