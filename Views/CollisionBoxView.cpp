#include "CollisionBoxView.h"
#include "../Models/Polygon.h"

void drawCollisionBoxes() {
    std::list<Polygon> secondList(polygonList);
    while(!secondList.empty()) {
        Polygon p = secondList.back();

        double vct1_1[] = {p[1].x, p[1].z};
        double vct2_1[] = {p[2].x, p[2].z};
        double vct3_1[] = {p[3].x, p[3].z};
        double vct4_1[] = {p[4].x, p[4].z};
        glBegin(GL_QUADS);
        glColor3d(0.5, 0.5, 1);
        glVertex3d(vct1_1[0], 0.1, vct1_1[1]);
        glVertex3d(vct2_1[0], 0.1, vct2_1[1]);
        glColor3d(0.5, 1, 0.5);
        glVertex3d(vct3_1[0], 0.1, vct3_1[1]);
        glVertex3d(vct4_1[0], 0.1, vct4_1[1]);
        glEnd();
        secondList.pop_back();
    }

    /*double vct1[] = {0.748597, -5.294455};
    double vct2[] = {0.600000, -5.500000};
    double vct3[] = {1.975371, -6.388843};
    double vct4[] = {2.134902, -6.103373};
    glBegin(GL_QUADS);
    glVertex3d(vct1[0], 0.1, vct1[1]);
    glVertex3d(vct2[0], 0.1, vct2[1]);
    glVertex3d(vct3[0], 0.1, vct3[1]);
    glVertex3d(vct4[0], 0.1, vct4[1]);
    glEnd();*/
}
