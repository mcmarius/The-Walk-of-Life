#include "GroundView.h"

void drawGround() {
    glColor3d(1, 1, 0);
    glBegin(GL_QUADS);
    /*glTexCoord2d(0.0, 0.0); */glVertex3d(-2000, 0, -2000);
    /*glTexCoord2d(0.0, 1500.0); */glVertex3d(-2000, 0, 2000);
    /*glTexCoord2d(1500.0, 1500.0); */glVertex3d(2000, 0, 2000);
    /*glTexCoord2d(1500.0, 0.0); */glVertex3d(2000, 0, -2000);
    glEnd();
}
