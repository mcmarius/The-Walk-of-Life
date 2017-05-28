#include "GroundView.h"

GLuint _grassTexture;
GLuint _pathTexture;

void loadGrassTexture(void) {
        GLsizei width2 = 0, height2 = 0;

        unsigned char *image2 = SOIL_load_image("Textures/grass.jpg", &width2, &height2, 0, SOIL_LOAD_RGB);
        glGenTextures(1, &_grassTexture);
        glBindTexture(GL_TEXTURE_2D, _grassTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // Set texture1 wrapping to GL_REPEAT
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        SOIL_free_image_data(image2);
        glBindTexture(GL_TEXTURE_2D, 0);
}


void loadPathTexture(void) {
    GLsizei width2 = 0, height2 = 0;
    unsigned char *image2 = SOIL_load_image("Textures/path.jpg", &width2, &height2, 0, SOIL_LOAD_RGB);
    glGenTextures(1, &_pathTexture);
    glBindTexture(GL_TEXTURE_2D, _pathTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // Set texture1 wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    SOIL_free_image_data(image2);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawGround(){
   // glColor3d(1, 1, 0);

    // Draw ground and grass
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _grassTexture);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3d(-2000, 0.0, -2000);
    glTexCoord2d(0.0, 1500.0); glVertex3d(-2000, 0.0, 2000);
    glTexCoord2d(1500.0, 1500.0); glVertex3d(2000, 0.0, 2000);
    glTexCoord2d(1500.0, 0.0); glVertex3d(2000, 0.0, -2000);
 /*glTexCoord3f(0.0,70.0,1);  glVertex3f(-50,-1.5,50);

    glTexCoord3f(0.0,0.0,-1);  glVertex3f(-50,-1.5,-50);

    glTexCoord3f(70.0,0.0,-1);  glVertex3f(50,-1.5,-50);

    glTexCoord3f(70.0,70.0,1);  glVertex3f(50,-1.5,50);*/



    glEnd();
    glDisable(GL_TEXTURE_2D);


    glPushMatrix();

    glRotated(30.0,0.0,1.0,0.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _pathTexture);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3d(2.5,0.01,-6.0);
    glTexCoord2d(0.0, 15.0);glVertex3f(2.5,0.01,5.0);
    glTexCoord2d(1.0, 15.0); glVertex3f(3.5,0.01,5.0);
    glTexCoord2d(1.0, 0.0); glVertex3f(3.5,0.01,-6.0);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();





}


