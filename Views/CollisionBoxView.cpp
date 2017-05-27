#include "CollisionBoxView.h"

void drawCollisionBoxes() {
    glColor3d(1, 0.5, 1);

    double vct1_1[] = {-1.359682, -4.109242};
    double vct2_1[] = {-2.497730, -6.018492};
    double vct3_1[] = {-2.274956, -6.037777};
    double vct4_1[] = {-1.150000, -4.250000};
    glBegin(GL_QUADS);
    glVertex3d(vct1_1[0], 0.1, vct1_1[1]);
    glVertex3d(vct2_1[0], 0.1, vct2_1[1]);
    glVertex3d(vct3_1[0], 0.1, vct3_1[1]);
    glVertex3d(vct4_1[0], 0.1, vct4_1[1]);
    glEnd();
    double vct1[] = {0.748597, -5.294455};
    double vct2[] = {0.600000, -5.500000};
    double vct3[] = {1.975371, -6.388843};
    double vct4[] = {2.134902, -6.103373};
    glBegin(GL_QUADS);
    glVertex3d(vct1[0], 0.1, vct1[1]);
    glVertex3d(vct2[0], 0.1, vct2[1]);
    glVertex3d(vct3[0], 0.1, vct3[1]);
    glVertex3d(vct4[0], 0.1, vct4[1]);
    glEnd();
}
