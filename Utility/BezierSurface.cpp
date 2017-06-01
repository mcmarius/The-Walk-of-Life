//
// Created by marius on 01/06/2017.
// Coordinates obtained using https://www.geogebra.org/m/XktMDtsJ
//

#include "BezierSurface.h"

const int imageWidth  = 64;
const int imageHeight = 64;
const int gridN = 100;
GLubyte image[3 * imageWidth * imageHeight];

void makeImage() {
    int i, j;
    double ti, tj;

    for(i = 0; i < imageWidth; i++) {
        ti = 2.0 * 3.14159265 * i / imageWidth;
        for(j = 0; j < imageHeight; j++) {
            tj = 2.0 * 3.14159265 * j / imageHeight;

            image[3 * (imageHeight * i + j)] = (GLubyte) ((GLubyte) 127 * (1.0 + sin(ti)));
            image[3 * (imageHeight * i + j) + 1] = (GLubyte) ((GLubyte) 127 * (1.0 + cos(2 * tj)));
            image[3 * (imageHeight * i + j) + 2] = (GLubyte) ((GLubyte) 127 * (1.0 + cos(ti + tj)));
        }
    }
}

void initBezierGroundSurface() {
    GLdouble controlPoints[4][4][3] = {
    {{4.905, -2.696, 3.180}, {-1.000, -6.000, 3.868},
     {-1.399, 2.480, 3.542}, {-1.539, 4.105, 3.000}},
    {{3.248, -2.113, 3.000}, {-1.412, -0.092, 2.500},
     {1.226, -0.923, 4.264}, {0.137, 2.395, 3.138}},
    {{4.149, -0.210, 2.778}, {3, 1, 3},
     {1.065, 0.476, 4.581}, {1.089, 4.315, 3.176}},
    {{4, 0, 2}, {3, 1, 1},
     {3, 0, 3}, {1, 0, 3}}};

    GLfloat texPoints[2][2][2] = {{{0.0, 0.0}, {0.0, 1.0}},
                                  {{1.0, 0.0}, {1.0, 1.0}}};
    glClearColor(0.99, 0.9, 1.0, 0.0);
    glMap2d(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
            0, 1, 12, 4, &controlPoints[0][0][0]);
    glMap2f(GL_MAP2_TEXTURE_COORD_2, 0, 1, 2, 2,
            0, 1, 4, 2, &texPoints[0][0][0]);
    glEnable(GL_MAP2_TEXTURE_COORD_2);
    glEnable(GL_MAP2_VERTEX_3);
    glMapGrid2f(gridN, 0.0, 1.0, gridN, 0.0, 1.0);
    makeImage();
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}
void displayBezierGroundSurface(GLdouble x, GLdouble z) {
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslated(0 + x, -3.1, 6 + z);
    glRotated(90, -1, 0, 0);

    glColor3f(0.0, 1.0, 0.0);
    glEvalMesh2(GL_FILL, 0, gridN, 0, gridN);

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
