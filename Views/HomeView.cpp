#include "HomeView.h"

GLuint textureBrick, textureDoor, textureRoof, textureWindow,textureFloor;
const float angleHouse = 30;



void write (const char *string)
{
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
}

GLuint loadTexture(Image* image) {

    GLuint textureId;
    glGenTextures(1, &textureId); //Make room for our texture
    glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
    //Map the image to the texture
    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
                 0,                            //0 for now
                 GL_RGB,                       //Format OpenGL uses for image
                 image->width, image->height,  //Width and height
                 0,                            //The border of the image
                 GL_RGB, //GL_RGB, because pixels are stored in RGB format
                 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
            //as unsigned numbers
                 image->pixels);               //The actual pixel data
    return textureId; //Returns the id of the texture
}




void loadTextureOfHouse(void)
{



    Image* image = loadBMP("Textures/bricks.bmp");
    textureBrick = loadTexture(image);

    image = loadBMP("Textures/door.bmp");
    textureDoor = loadTexture(image);

    image = loadBMP("Textures/roof.bmp");
    textureRoof = loadTexture(image);

    image = loadBMP("Textures/window.bmp");
    textureWindow = loadTexture(image);

    image = loadBMP("Textures/floor.bmp");
    textureFloor = loadTexture(image);


    delete image;
}


void drawAHome() {



/*    glColor3d(1.0,1.0,1.0);
    glRasterPos3f(1,2.0,-4.0);
    write ("Nu e bine domnule student !");*/



    glEnable(GL_TEXTURE_2D);

    // Front side
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, textureBrick);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTranslatef(0,0,-6);
    glRotatef(angleHouse, 0.0, 1.0, 0.0);
    glBegin(GL_QUADS);  // Wall
    glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-2,1.5,1);
    glTexCoord3f(4.0,2.0,0.1);  glVertex3f(2,1.5,1);
    glTexCoord3f(4.0,0.0,0.1);  glVertex3f(2,0.0,1);
    glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-2,0.0,1);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureRoof);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);  // Roof
    glTexCoord3f(0.0,2.0,0); glVertex3f((GLfloat) -2.2, 2.0, 0);
    glTexCoord3f(4.0,2.0,0);glVertex3f(2.2,2.0,0);
    glTexCoord3f(4.0,0.0,1.25); glVertex3f(2.2,1.4,1.25);
    glTexCoord3f(0.0,0.0,1.25); glVertex3f((GLfloat) -2.2, 1.4, 1.25);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureDoor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);  // Door
    glTexCoord3f(0.0,1.0,1.0001); glVertex3f((GLfloat) -0.3, 1.1, 1.0001);
    glTexCoord3f(1.0,1.0,1.0001); glVertex3f(0.3,1.1,1.0001);
    glTexCoord3f(1.0,0.0,1.0001); glVertex3f(0.3,0.0,1.0001);
    glTexCoord3f(0.0,0.0,1.0001); glVertex3f((GLfloat) -0.3, 0.0, 1.0001);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureWindow);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);  // Window Left
    glTexCoord3f(0.0,1.0,1.0001); glVertex3f((GLfloat) -1.5, 1.2, 1.0001);
    glTexCoord3f(1.0,1.0,1.0001); glVertex3f((GLfloat) -0.75, 1.2, 1.0001);
    glTexCoord3f(1.0,0.0,1.0001); glVertex3f((GLfloat) -0.75, 0.7, 1.0001);
    glTexCoord3f(0.0,0.0,1.0001); glVertex3f((GLfloat) -1.5, 0.7, 1.0001);
    glEnd();

    glBegin(GL_QUADS);  // Window Right
    glTexCoord3f(0.0,1.0,1.0001); glVertex3f(1.5,1.2,1.0001);
    glTexCoord3f(1.0,1.0,1.0001); glVertex3f(0.75,1.2,1.0001);
    glTexCoord3f(1.0,0.0,1.0001); glVertex3f(0.75,0.7,1.0001);
    glTexCoord3f(0.0,0.0,1.0001); glVertex3f(1.5,0.7,1.0001);
    glEnd();
    glPopMatrix();

    // Back side
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureBrick);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTranslatef(0,0,-6);
    glRotatef(angleHouse, 0.0, 1.0, 0.0);
    glBegin(GL_QUADS);  // Wall
    glTexCoord3f(0.0,2.0,-1);  glVertex3f(-2,1.5,-1);
    glTexCoord3f(4.0,2.0,-1);  glVertex3f(2,1.5,-1);
    glTexCoord3f(4.0,0.0,-1);  glVertex3f(2,0.0,-1);
    glTexCoord3f(0.0,0.0,-1);  glVertex3f(-2,0.0,-1);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureRoof);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);  // Roof
    glTexCoord3f(0.0,2.0,0); glVertex3f((GLfloat) -2.2, 2.0, 0);
    glTexCoord3f(4.0,2.0,0);glVertex3f(2.2,2.0,0);
    glTexCoord3f(4.0, 0.0, (GLfloat) -1.25); glVertex3f(2.2, 1.4, (GLfloat) -1.25);
    glTexCoord3f(0.0, 0.0, (GLfloat) -1.25); glVertex3f((GLfloat) -2.2, 1.4, (GLfloat) -1.25);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureWindow);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);  // Window Left
    glTexCoord3f(0.0, 1.0, (GLfloat) -1.0001); glVertex3f((GLfloat) -1.5, 1.2, (GLfloat) -1.0001);
    glTexCoord3f(1.0, 1.0, (GLfloat) -1.0001); glVertex3f((GLfloat) -0.75, 1.2, (GLfloat) -1.0001);
    glTexCoord3f(1.0, 0.0, (GLfloat) -1.0001); glVertex3f((GLfloat) -0.75, 0.7, (GLfloat) -1.0001);
    glTexCoord3f(0.0, 0.0, (GLfloat) -1.0001); glVertex3f((GLfloat) -1.5, 0.7, (GLfloat) -1.0001);
    glEnd();

    glBegin(GL_QUADS);  // Window Right
    glTexCoord3f(0.0,1.0,1.0001); glVertex3f(1.5, 1.2, (GLfloat) -1.0001);
    glTexCoord3f(1.0,1.0,1.0001); glVertex3f(0.75, 1.2, (GLfloat) -1.0001);
    glTexCoord3f(1.0,0.0,1.0001); glVertex3f(0.75, 0.7, (GLfloat) -1.0001);
    glTexCoord3f(0.0,0.0,1.0001); glVertex3f(1.5, 0.7, (GLfloat) -1.0001);
    glEnd();
    glPopMatrix();

    // Right side
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textureBrick);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTranslatef(0,0,-6);
    glRotatef(angleHouse, 0.0, 1.0, 0.0);
    glBegin(GL_QUADS);  // Wall
    glTexCoord3f(0.0,2.0,1); glVertex3f(2,1.5,1);
    glTexCoord3f(2.0,2.0,-1); glVertex3f(2,1.5,-1);
    glTexCoord3f(2.0,0.0,-1); glVertex3f(2,0.0,-1);
    glTexCoord3f(0.0,0.0,1); glVertex3f(2,0.0,1);
    glEnd();

    glBegin(GL_TRIANGLES);  // Wall Upper
    glTexCoord3f(0.0,1.0,0); glVertex3f(2,2.0,0);
    glTexCoord3f(1.0,0.0,1); glVertex3f(2,1.5,1);
    glTexCoord3f((GLfloat)-1.0,0.0,-1); glVertex3f(2,1.5,-1);
    glEnd();
    glPopMatrix();

    // Left side
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textureBrick);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTranslatef(0,0,-6);
    glRotatef(angleHouse, 0.0, 1.0, 0.0);
    glBegin(GL_QUADS);  // Wall
    glTexCoord3f(0.0,2.0,1);    glVertex3f(-2,1.5,1);
    glTexCoord3f(2.0,2.0,-1);    glVertex3f(-2,1.5,-1);
    glTexCoord3f(2.0,0.0,-1);    glVertex3f(-2,0.0,-1);
    glTexCoord3f(0.0,0.0,1);    glVertex3f(-2,0.0,1);
    glEnd();

    glBegin(GL_TRIANGLES);  // Wall Upper
    glTexCoord3f(0.0,1.0,0);    glVertex3f(-2,2.0,0);
    glTexCoord3f(1.0,0.0,1);    glVertex3f(-2,1.5,1);
    glTexCoord3f((GLfloat)-1.0,0.0,-1);    glVertex3f(-2,1.5,-1);
    glEnd();
    glPopMatrix();


    glPushMatrix();

   // glRotatef(angleHouse, 0.0, 1.0, 0.0);


    glBindTexture(GL_TEXTURE_2D, textureFloor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glRotatef(angleHouse, 0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glTexCoord3f(0.0,2.0,1); glVertex3f(5,0.011,(GLfloat)-6.25);
    glTexCoord3f(2.0,2.0,-1); glVertex3f(1,0.01,(GLfloat)-6.25);
    glTexCoord3f(2.0,0.0,-1); glVertex3f(1,0.01,(GLfloat)-4.20);
    glTexCoord3f(0.0,0.0,1);  glVertex3f(5,0.01,(GLfloat)-4.20);

    glEnd();


    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}

