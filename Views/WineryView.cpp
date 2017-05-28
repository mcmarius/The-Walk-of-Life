#include "WineryView.h"




void drawWineryBar(){
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 1280, 720, 0.0, -1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glDisable(GL_CULL_FACE);

    glClear(GL_DEPTH_BUFFER_BIT);


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 0.7);
    glVertex2f(1000.0, 5.0);
    glVertex2f(alcohol_level, 5.0);
    glVertex2f(alcohol_level, 15.0);
    glVertex2f(1000.0, 15.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0);
    glVertex2f(1000.0, 5.0);
    glVertex2f(1200.0, 5.0);
    glVertex2f(1200.0, 15.0);
    glVertex2f(1000.0, 15.0);
    glEnd();







// Making sure we can render 3d again
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}