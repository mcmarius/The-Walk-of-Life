#include "PlayerView.h"

extern double x, y, z;
extern double lx, ly, lz;
extern double angle;

//bool loadedPlayerTexture = false;
GLuint faceTexture, rightSideTexture, leftSideTexture;
GLuint backSideTexture;
GLuint chestTexture;

void loadPlayerTexture(const std::string nume, GLuint &id) {
    GLsizei width = 0, height = 0;
    unsigned char *image = SOIL_load_image(nume.data(), &width, &height, 0, SOIL_LOAD_RGB);

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // Set texture1 wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawPlayer() {
    /*if(!loadedPlayerTexture) {
        loadedPlayerTexture = true;
        loadPlayerTexture("Textures/player_texture.png", faceTexture);
//        loadPlayerTexture("Textures/Player/right_ear.png", rightSideTexture);
//        loadPlayerTexture("Textures/Player/left_ear.png", leftSideTexture);
    }*/
    double zero = 0, coord = 0.2;
    glPushMatrix();
    glTranslated(x + lx, fmax(y - 0.1, 0.5), z + lz);
    glRotated(angle, 0, 1, 0);
    //glColor3d(0.5, 0.5, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, faceTexture);
    glBegin(GL_QUADS);      // the face
    glTexCoord2d(0.0,0.0); glVertex3d(zero, zero, zero);//  glTexCoord2d(0, 0);
    glTexCoord2d(0.0,1.0); glVertex3d(zero, coord, zero);//   glTexCoord2d(0.115, 0);
    glTexCoord2d(1.0,1.0); glVertex3d(coord, coord, zero);//    glTexCoord2d(0.115, 0.115);
    glTexCoord2d(1.0,0.0); glVertex3d(coord, zero, zero);//   glTexCoord2d(0, 0.115);
    glEnd();
//    glDisable(GL_TEXTURE_2D);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, rightSideTexture);
    glBegin(GL_QUADS);      // the right ear
    glVertex3d(coord, zero, zero);
    glTexCoord2d(0, 0);
    glVertex3d(coord, zero, coord);
    glTexCoord2d(0, 1);
    glVertex3d(coord, coord, coord);
    glTexCoord2d(1, 1);
    glVertex3d(coord, coord, zero);
    glTexCoord2d(1, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, leftSideTexture);
    glBegin(GL_QUADS);      // the left ear
    glTexCoord2d(1, 0); glVertex3d(zero, zero, zero);//glTexCoord2d(1, 0);
    glTexCoord2d(0, 0); glVertex3d(zero, zero, coord);//glTexCoord2d(1, 1);
    glTexCoord2d(0, 1); glVertex3d(zero, coord, coord);//glTexCoord2d(0, 1);
    glTexCoord2d(1, 1); glVertex3d(zero, coord, zero);//glTexCoord2d(0, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, backSideTexture);
    glBegin(GL_QUADS);      // the back
    glTexCoord2d(0.0,0.0);   glVertex3d(zero, zero, coord);
    glTexCoord2d(0.0,1.0);    glVertex3d(zero, coord, coord);
    glTexCoord2d(1.0,1.0);    glVertex3d(coord, coord, coord);
    glTexCoord2d(1.0,0.0);    glVertex3d(coord, zero, coord);
    glEnd();
    glBegin(GL_QUADS);      // barbia
        glVertex3d(zero, zero, zero);
        glVertex3d(zero, zero, coord);
        glVertex3d(coord, zero, coord);
        glVertex3d(coord, zero, zero);
    glEnd();
    glBegin(GL_QUADS);      // chelia
        glVertex3d(zero, coord, zero);
        glVertex3d(zero, coord, coord);
        glVertex3d(coord, coord, coord);
        glVertex3d(coord, coord, zero);
    glEnd();


    //glColor3d(0.0,0.2,1.0);
    glBegin(GL_QUADS);

    glVertex3d(zero-0.1, zero -0.02, zero);
    glVertex3d(zero-0.1, zero -0.02, coord);
    glVertex3d(coord+0.1,zero -0.02, coord);
    glVertex3d(coord+0.1,zero -0.02, zero);

    glEnd();



    glBindTexture(GL_TEXTURE_2D, chestTexture);

    glBegin(GL_QUADS);

    glTexCoord2d(0.88,0.88); glVertex3d(zero-0.1, zero -0.02, zero);
    glTexCoord2d(0.88,0.7); glVertex3d(zero-0.1, zero -0.08, zero);
    glTexCoord2d(0.0,0.7); glVertex3d(coord+0.1,zero -0.08, zero);
    glTexCoord2d(0.0,0.88); glVertex3d(coord+0.1,zero -0.02, zero);

    glEnd();



    glBegin(GL_QUADS);

     glVertex3d(zero-0.1, zero -0.02, zero+0.2);
     glVertex3d(zero-0.1, zero -0.08, zero+0.2);
     glVertex3d(coord+0.1,zero -0.08, zero+0.2);
     glVertex3d(coord+0.1,zero -0.02, zero+0.2);

    glEnd();


    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
