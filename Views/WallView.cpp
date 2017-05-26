#include "WallView.h"

GLUquadricObj *qobj;
GLuint startList;

GLfloat mat_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat model_ambient[] = { 0.5, 0.5, 0.5, 1.0 };


void drawAStick(void)
{
   // glClearColor(0.0, 0.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);



    startList = glGenLists(2);
    qobj = gluNewQuadric();


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
   // glEnable(GL_DEPTH_TEST);


    gluQuadricDrawStyle(qobj, GLU_FILL); /* flat shaded */
    gluQuadricNormals(qobj, GLU_FLAT);
    glNewList(startList, GL_COMPILE);
    gluCylinder(qobj, 0.1, 0.1, 1.0, 15, 5);
    glEndList();


    gluQuadricDrawStyle(qobj, GLU_FILL); /* flat shaded */
    gluQuadricNormals(qobj, GLU_FLAT);
    glNewList(startList+1, GL_COMPILE);
    gluCylinder(qobj, 0.1, 0.01, 0.3, 15, 5);
    glEndList();

//    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

   // glColor3d(1.0,0.0,0.0);
    glTranslatef(0.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glCallList(startList);


    //   glDisable(GL_DEPTH_TEST);


    glPopMatrix();

    glPushMatrix();




    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glCallList(startList+1);
    glPopMatrix();

    glPopMatrix();

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);


}


void drawFence(void) {
        glPushMatrix();
        glTranslated(0.0, 0.0, 0.0);
        drawAStick();
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.2, 0.0, 0.0);
        drawAStick();
        glPopMatrix();

         glPushMatrix();
         glTranslated(0.4, 0.0, 0.0);
         drawAStick();
         glPopMatrix();

}