#include "PlayerView.h"

extern double x, y, z;
extern double lx, ly, lz;

void drawPlayer() {
    glTranslated(x + lx, std::fmax(y + ly - 0.1, 0.5), z + lz);
    glPushMatrix();
    glColor3d(0, 1, 1);
    glScaled(0.5, 0.5, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
}
