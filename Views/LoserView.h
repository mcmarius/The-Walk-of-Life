//
// Created by andre on 6/7/2017.
//

#ifndef THE_WALK_OF_LIFE_LOSERVIEW_H
#define THE_WALK_OF_LIFE_LOSERVIEW_H

//#include <GL/freeglut.h>

#include "../main.h"
#include <string>

void drawLoserView();
void loserKeyboard(unsigned char key, int, int);
void printTextMessage();
void glPrint(double *p, std::string sir, int lungime);

#endif //THE_WALK_OF_LIFE_LOSERVIEW_H
