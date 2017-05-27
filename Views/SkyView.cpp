#include "SkyView.h"

const int size = 100;

GLuint _skyTexture;


void loadSkyTexture(void) {
    GLsizei width2 = 0, height2 = 0;
    unsigned char *image2 = SOIL_load_image("../Textures/night_sky.png", &width2, &height2, 0, SOIL_LOAD_RGB);
    glGenTextures(1, &_skyTexture);
    glBindTexture(GL_TEXTURE_2D, _skyTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // Set texture1 wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    SOIL_free_image_data(image2);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void skybox(void) {

    glPushMatrix();
//    glClear(GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();

    /*gluLookAt( 0.0, 0.0, 0.0,
               1.0, 0.0, 0.0,
               0.0, 1.0, 0.0);*/

 //   glPushAttrib(GL_ENABLE_BIT);
   // glDisable(GL_DEPTH_TEST);
    //glDisable(GL_LIGHTING);
   // glDisable(GL_BLEND);
//    glDepthMask(0);

    glColor4f(1, 1, 1, 1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _skyTexture);
    glBegin(GL_QUADS);        					//FRONT
    glVertex3f(-size,  size, size); glTexCoord2d(0, 1);
    glVertex3f( size,  size, size); glTexCoord2d(1, 1);
    glVertex3f( size, -size, size); glTexCoord2d(1, 0);
    glVertex3f(-size, -size, size); glTexCoord2d(0, 0);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, _skyTexture);

    glBegin(GL_QUADS);        					//BACK
    glVertex3f(-size,  size, -size); glTexCoord2d(0, 1);
    glVertex3f( size,  size, -size); glTexCoord2d(1, 1);
    glVertex3f( size, -size, -size); glTexCoord2d(1, 0);
    glVertex3f(-size, -size, -size); glTexCoord2d(0, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, _skyTexture);

    glBegin(GL_QUADS);        					//TOP
    glVertex3f(-size,  size,  size); glTexCoord2d(0, 1);
    glVertex3f(-size,  size, -size); glTexCoord2d(1, 1);
    glVertex3f( size,  size, -size); glTexCoord2d(1, 0);
    glVertex3f( size,  size,  size); glTexCoord2d(0, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, _skyTexture);

    glBegin(GL_QUADS);        					//BOTTOM
    glVertex3f(-size, -size,  size); glTexCoord2d(0, 1);
    glVertex3f( size, -size,  size); glTexCoord2d(1, 1);
    glVertex3f( size, -size, -size); glTexCoord2d(1, 0);
    glVertex3f(-size, -size, -size); glTexCoord2d(0, 0);
    glEnd();

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, _skyTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);        					//RIGHT SIDE
    glVertex3f( size,  size,  size); glTexCoord2d(0, 1);
    glVertex3f( size, -size,  size); glTexCoord2d(1, 1);
    glVertex3f( size, -size, -size); glTexCoord2d(1, 0);
    glVertex3f( size,  size, -size); glTexCoord2d(0, 0);
    glEnd();




    glBindTexture(GL_TEXTURE_2D, _skyTexture);
    glBegin(GL_QUADS);        					//LEFT SIDE
    glVertex3f(-size,  size,  size); glTexCoord2d(0, 1);
    glVertex3f(-size, -size,  size); glTexCoord2d(1, 1);
    glVertex3f(-size, -size, -size); glTexCoord2d(1, 0);
    glVertex3f(-size,  size, -size); glTexCoord2d(0, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

   // glPopAttrib();
   glPopMatrix();


}