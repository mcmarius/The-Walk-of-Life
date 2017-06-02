//
// Created by marius on 02/06/2017.
//

#ifndef THE_WALK_OF_LIFE_SHADOWS_H
#define THE_WALK_OF_LIFE_SHADOWS_H

#include "../Views/HomeView.h"

//extern double x, lx, y, ly, z, lz;

//void shadowMatrix(GLfloat **shadowMat, GLfloat *groundPlane, GLfloat *lightPos);
void findPlane(GLfloat *plane, GLfloat *v0, GLfloat *v1, GLfloat *v2);
void initShadowMatrices();
void drawShadows();

#endif //THE_WALK_OF_LIFE_SHADOWS_H
