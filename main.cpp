#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <cmath>

#include "Models/Player.h"
#include "Views/GroundView.h"
#include "Views/HomeView.h"
//#include "Views/MiscView.h"
//#include "Views/ObstacleView.h"
#include "Views/PlayerView.h"
#include "Views/SkyView.h"
#include "Views/WallView.h"
#include "GameLogic.h"
//#include "Views/WineryView.h"

GLint winWidth = 1280, winHeight = 720;

extern GLuint faceTexture;

GLfloat ambient [ ] = {0, 0, 0, 1.0};
double angle, yAngle;
double lx, ly, lz = -1;
double x, y = 0.5, z;

const double PI = 3.1415926535, halfPI = PI / 2.;//, doublePI = 2 * PI;

void initialise();
void reshape(int width, int height);
void processNormalKeys(unsigned char key, int, int);
void processSpecialKeys(int key, int, int);
void draw();


void initialise() {
    // load all textures
    loadGrassTexture();
    loadTextureOfHouse();
    loadSkyTexture();
  //  loadPlayerTexture("Textures/player_texture.png", faceTexture);

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
    switch(key) {
        case 'd' :
            angle += 0.05;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case 'a' :
            angle -= 0.05;
            lx = sin(angle);
            lz = -cos(angle);
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
        default:
            break;
    }
    if(key == 27)
        exit(0);
}

void processSpecialKeys(int key, int /*xx*/, int /*yy*/) {

    double fraction = 0.1;
    if(!anyCollisions(x + lx, z + lz)) {
        switch(key) {
            case GLUT_KEY_LEFT :
                x -= sin(angle + halfPI) * fraction;
                z += cos(angle + halfPI) * fraction;
                break;
            case GLUT_KEY_RIGHT :
                x += sin(angle + halfPI) * fraction;
                z -= cos(angle + halfPI) * fraction;
                break;
            case GLUT_KEY_UP :
                x += lx * fraction;
                z += lz * fraction;
                break;
            case GLUT_KEY_DOWN :
                x -= lx * fraction;
                z -= lz * fraction;
                break;
            default:
                break;
        }
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

    gluLookAt(x, y + 0.25, z,
              x + lx, y + ly + 0.25, z + lz,
              0.0, 0.75, 0.0);


    drawGround();

    drawAHome();
   // drawFence();

    drawPlayer();


    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char **argv) {
    Player player;      // just to avoid warnings
    player.collectPrize();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("The Walk of Life");

    initialise();

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutIdleFunc(draw);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);


    glEnable(GL_DEPTH_TEST);    // OpenGL init
    glutMainLoop();    // enter GLUT event processing cycle
    return 0;
}
