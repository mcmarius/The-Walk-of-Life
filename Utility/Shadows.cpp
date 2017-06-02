//
// Created by marius on 02/06/2017.
//

//#include <cstdio>
#include "Shadows.h"
//#include "../Views/PlayerView.h"
//#include "../Views/BottleView.h"
//#include "../Views/WallView.h"

enum {
    X, Y, Z, W
};
enum {
    A, B, C, D
};


GLfloat groundShadow[4][4];

GLfloat lightPos[] =
{1, 0.2, -2, 1.f};
GLuint lightList = 20;//, coneList = 30;
/*void cone() {
    glPushMatrix();
    glTranslatef(-0.f, 3.f, -0.f);
    glCallList(coneList);
    glPopMatrix();
}*/

/* create a matrix that will project the desired shadow */
void shadowMatrix(GLfloat shadowMat[4][4], GLfloat *groundPlane, GLfloat *lightPos) {
    GLfloat dot;

    /* find dot product between light position vector and ground plane normal */
    dot = groundPlane[X] * lightPos[X] +
          groundPlane[Y] * lightPos[Y] +
          groundPlane[Z] * lightPos[Z] +
          groundPlane[W] * lightPos[W];

    shadowMat[0][0] = dot - lightPos[X] * groundPlane[X];
    shadowMat[1][0] = 0.f - lightPos[X] * groundPlane[Y];
    shadowMat[2][0] = 0.f - lightPos[X] * groundPlane[Z];
    shadowMat[3][0] = 0.f - lightPos[X] * groundPlane[W];

    shadowMat[X][1] = 0.f - lightPos[Y] * groundPlane[X];
    shadowMat[1][1] = dot - lightPos[Y] * groundPlane[Y];
    shadowMat[2][1] = 0.f - lightPos[Y] * groundPlane[Z];
    shadowMat[3][1] = 0.f - lightPos[Y] * groundPlane[W];

    shadowMat[X][2] = 0.f - lightPos[Z] * groundPlane[X];
    shadowMat[1][2] = 0.f - lightPos[Z] * groundPlane[Y];
    shadowMat[2][2] = dot - lightPos[Z] * groundPlane[Z];
    shadowMat[3][2] = 0.f - lightPos[Z] * groundPlane[W];

    shadowMat[X][3] = 0.f - lightPos[W] * groundPlane[X];
    shadowMat[1][3] = 0.f - lightPos[W] * groundPlane[Y];
    shadowMat[2][3] = 0.f - lightPos[W] * groundPlane[Z];
    shadowMat[3][3] = dot - lightPos[W] * groundPlane[W];
}

/* find the plane equation given 3 points */
void findPlane(GLfloat *plane, GLfloat *v0, GLfloat *v1, GLfloat *v2) {
    GLfloat vec0[3], vec1[3];

    /* need 2 vectors to find cross product */
    vec0[X] = v1[X] - v0[X];
    vec0[Y] = v1[Y] - v0[Y];
    vec0[Z] = v1[Z] - v0[Z];

    vec1[X] = v2[X] - v0[X];
    vec1[Y] = v2[Y] - v0[Y];
    vec1[Z] = v2[Z] - v0[Z];

    /* find cross product to get A, B, and C of plane equation */
    plane[A] = vec0[Y] * vec1[Z] - vec0[Z] * vec1[Y];
    plane[B] = -(vec0[X] * vec1[Z] - vec0[Z] * vec1[X]);
    plane[C] = vec0[X] * vec1[Y] - vec0[Y] * vec1[X];

    plane[D] = -(plane[A] * v0[X] + plane[B] * v0[Y] + plane[C] * v0[Z]);
}

void initShadowMatrices() {
    GLfloat plane[4];
    GLfloat v0[3], v1[3], v2[3];
    v0[X] = -1.f; v0[Y] = 0.04f; v0[Z] = -1.f;
    v1[X] = 1.f; v1[Y] = 0.04f; v1[Z] = -1.f;
    v2[X] = 1.f; v2[Y] = 0.04f; v2[Z] = 1.f;

    findPlane(plane, v0, v1, v2);
    shadowMatrix(groundShadow, plane, lightPos);
/*
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            printf("%.3f\t", groundShadow[i][j]);
        }
        printf("\n");
    }*/

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glNewList(lightList, GL_COMPILE);
    gluSphere(gluNewQuadric(), 0.5, 20, 20);
    glEndList();

    /*glNewList(coneList, GL_COMPILE);
    gluCylinder(gluNewQuadric(), 2, 0, 6, 20, 20);
    glEndList();*/
}

void drawShadows() {
/*    glBegin(GL_QUADS);
    glNormal3f(0.f, 1.f, 0.f);
    glVertex3f(-100.f, -100.f, -320.f);
    glVertex3f(100.f, -100.f, -320.f);
    glVertex3f(100.f, -100.f, -520.f);
    glVertex3f(-100.f, -100.f, -520.f);
    glEnd();*/

    glDisable(GL_LIGHTING);
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glColor3f(0.f, 0.f, 0.f);  /* shadow color */
    glPushMatrix();
    glRotated(180, 0, 1, 0);
    glTranslatef(-1.3f, 0, 9.1);
    glMultMatrixf((GLfloat *) groundShadow);
    drawAHome();
    glPopMatrix();


/*    glPushMatrix();
    glTranslatef(lightPos[X], lightPos[Y], lightPos[Z]);
    //glDisable(GL_LIGHTING);
    glColor3f(1.f, 1.f, .7f);
    glCallList(lightList);
    glPopMatrix();*/

    glEnable(GL_LIGHTING);

//    cone();
}

