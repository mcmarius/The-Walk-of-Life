#include "PlayerView.h"

extern double x, y, z;
extern double lx, ly, lz;
extern double angle;

bool loadedPlayerTexture = false;
GLuint faceTexture;//, rightSideTexture, leftSideTexture;

void loadPlayerTexture(const std::string nume, GLuint &id) {
    GLsizei width = 0, height = 0;
    unsigned char *image = SOIL_load_image(nume.data(), &width, &height, 0, SOIL_LOAD_RGB);

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);  // Set texture1 wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawPlayer() {
    if(!loadedPlayerTexture) {
        loadedPlayerTexture = true;
        loadPlayerTexture("Textures/player_texture.png", faceTexture);
//        loadPlayerTexture("Textures/Player/right_ear.png", rightSideTexture);
//        loadPlayerTexture("Textures/Player/left_ear.png", leftSideTexture);
    }
    double zero = 0, coord = 0.2;
    glPushMatrix();
    glTranslated(x +lx, std::fmax(y - 0.1, 0.5) + 0.05, z + lz);
//    glTranslated(-coord, 0, coord);
    glRotated(angle, 0, 1, 0);
//    glTranslated(coord/2, 0, -coord/2);
//    glTranslated(-lx - 0.1, 0, -lz + 0.2);
    glColor3d(1, 1, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, faceTexture);
    glBegin(GL_QUADS);      // the face
        glVertex3d(zero, zero, zero);  glTexCoord2d(0, 0);
        glVertex3d(zero, coord, zero);   glTexCoord2d(0.115, 0);
        glVertex3d(coord, coord, zero);    glTexCoord2d(0.115, 0.115);
        glVertex3d(coord, zero, zero);   glTexCoord2d(0, 0.115);
    glEnd();
//    glDisable(GL_TEXTURE_2D);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, 0);
//    glBindTexture(GL_TEXTURE_2D, rightSideTexture);
    glBegin(GL_QUADS);      // the right ear
    glVertex3d(coord, zero, zero);
//    glTexCoord2d(0, 0);
    glVertex3d(coord, zero, coord);
//    glTexCoord2d(0, 1);
    glVertex3d(coord, coord, coord);
//    glTexCoord2d(1, 1);
    glVertex3d(coord, coord, zero);
//    glTexCoord2d(1, 0);
    glEnd();
//    glColor3d(0., 0.75, 0.75);
//    glBindTexture(GL_TEXTURE_2D, leftSideTexture);
    glBegin(GL_QUADS);      // the left ear
    glVertex3d(zero, zero, zero);//glTexCoord2d(1, 0);
    glVertex3d(zero, zero, coord);//glTexCoord2d(1, 1);
    glVertex3d(zero, coord, coord);//glTexCoord2d(0, 1);
    glVertex3d(zero, coord, zero);//glTexCoord2d(0, 0);
    glEnd();
//    glDisable(GL_TEXTURE_2D);
//    glColor3d(0., 0., 1);
    glBegin(GL_QUADS);      // the back
        glVertex3d(zero, zero, coord);
        glVertex3d(zero, coord, coord);
        glVertex3d(coord, coord, coord);
        glVertex3d(coord, zero, coord);
    glEnd();
//    glColor3d(0., 0.75, 1);
//    glColor3d(0., 1, 0.75);
    glBegin(GL_QUADS);      // barbia
        glVertex3d(zero, zero, zero);
        glVertex3d(zero, zero, coord);
        glVertex3d(coord, zero, coord);
        glVertex3d(coord, zero, zero);
    glEnd();
//    glColor3d(0., 1, zero);
    glBegin(GL_QUADS);      // chelia
        glVertex3d(zero, coord, zero);
        glVertex3d(zero, coord, coord);
        glVertex3d(coord, coord, coord);
        glVertex3d(coord, coord, zero);
    glEnd();
    //glutSolidCube(0.3);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glColor3d(0, 0, 1);
    glScaled(0.1, 0.1, 0.1);
    glutSolidDodecahedron();    // obiect de test
}
