//
// Created by andre on 6/7/2017.
//

#include "WineryView.h"
#include "LoserView.h"

double zeta = 0;
extern double x, lx, y, ly, z, lz, balanceSpeed;
extern GLfloat ambient_mat_wine[], difuse_mat_wine[], specular_mat_wine[], shininess_mat_wine[];
extern GLuint objList;
extern bool ploaie, fog, balanceEnabled, balanceToRight, shadowsEnabled;
extern double alcohol_level;

void drawOneBottle();

void drawLoserView() {
    zeta += 2;
    x = y = z = 0;
    lx = ly = lz = 0;
    balanceSpeed = 0.02;
    //playerX = playerY = playerZ = -2000;
    glutSpecialFunc(NULL);
    glutKeyboardFunc(loserKeyboard);

    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3d(0, 1, 0);
    glTranslated(0, 0, -1);
    glPushMatrix();
    glRotated(45, 1, 0, 1);
    glTranslated(0, 0.5, 0);
    glRotated(zeta, -0.2, 1, 0.1);
    glTranslated(0, -0.5, 0);
    drawOneBottle();
    glPopMatrix();

//    glTranslated(0, -1, 0);
    drawWineryBar();
    printTextMessage();

    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();
}

void drawOneBottle() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_mat_wine);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difuse_mat_wine);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_mat_wine);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess_mat_wine);

    glPushMatrix();
//    glTranslated(1 , 1 , 1);
    glRotated(90.0,1.0,0.0,0.0);
    glutSolidCylinder(0.05,0.25,10,10);
    glPopMatrix();

    glPushMatrix();
//    glTranslated(1, 1, 1);
    glutSolidSphere(0.049,10,10);
    glPopMatrix();



    glPushMatrix();
//    glTranslated(1, 1, 1);
    glRotated(-90.0,1.0,0.0,0.0);
    glCallList(objList);
    glPopMatrix();

    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
}

void loserKeyboard(unsigned char key, int, int) {
    switch(key) {
        case 27:
            exit(0);
        case 'r':
            glutDisplayFunc(draw);
            glutIdleFunc(draw);
            glutKeyboardFunc(processNormalKeys);
            glutSpecialFunc(processSpecialKeys);
            x = 48.744983, y = 0.5, z = 78.729899;
            lx = ly = 0;
            lz = -1;
            ploaie = fog = balanceEnabled = balanceToRight = shadowsEnabled = false;
            alcohol_level = 1000;

            break;
        default:
            break;
    }

}

void glPrint(double *p, std::string sir, int lungime) {
    glColor3f(0, 0, 0);
    int i;
    for(i = 0; i<lungime; i++) {
        glRasterPos3d(p[0] + 15 * i, 0, 0);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, sir[i]);
    }
}

void printTextMessage() {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 1280, 720, 0.0, -1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glDisable(GL_CULL_FACE);

    glClear(GL_DEPTH_BUFFER_BIT);

    double pos[] = {5, 1, -1};
    glPushMatrix();
    glTranslated(0, 100, 0);
    glPrint(pos, "Din pacate, cetateanul s-a imbatat si nu si-a putut indeplini misiunea!", 71);
    glPopMatrix();
    //glRectd(-1, 1, 20, 20);

// Making sure we can render 3d again
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

