#include "WallView.h"

GLUquadricObj *qobj;
GLuint startList;

GLfloat mat_ambient[] = {0.19125, 0.0735, 0.0225, };
GLfloat mat_difuse[] = {0.8038, 	0.37048, 	0.0828};
GLfloat mat_specular[] = { 0.256777, 0.137622, 0.086014, };
GLfloat mat_shininess[] = { 0.1 };
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat model_ambient[] = { 0.5, 0.5, 0.5, 1.0 };


const float angleWall = 0;


void loadStickMaterial();

void drawAStick(void)
{


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
 //   glEnable(GL_DEPTH_TEST);


    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_difuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
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
   // glDisable(GL_DEPTH_TEST);


}

void loadStickMaterial() {// glClearColor(0.0, 0.0, 0.0, 0.0);

  //  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  //  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);


    startList = glGenLists(2);
    qobj = gluNewQuadric();





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
}


void drawFence(void) {

    glPushMatrix();
    glRotatef(angleWall, 0.0, 1.0, 0.0);


    glPushMatrix();
    glTranslated(-2.0,0.0,-3.0);

    for(double x = 0 ; x <= 4.6 ; x+=0.2) {
        glPushMatrix();
        glRotated(120.0,0.0,1.0,0.0);
        glTranslated(x, 0.0, 0.0);
        drawAStick();
        glPopMatrix();
    }

    glPopMatrix();


    glPushMatrix();

    glTranslated(-4.1,0.0,-7.0);

    for(double x = 0 ; x <= 6.2 ; x+=0.2){

        glPushMatrix();
        glRotated(30.0,0.0,1.0,0.0);
        glTranslated(x,0.0,0.0);
        drawAStick();
        glPopMatrix();

    }

    glPopMatrix();


    glPushMatrix();
    glTranslated(3.5,0.0,-6.0);

    for(double x = 0 ; x <= 4.6 ; x+=0.2){

        glPushMatrix();
        glRotated(120.0,0.0,1.0,0.0);
        glTranslated(x,0.0,0.0);
        drawAStick();
        glPopMatrix();
    }

    glPopMatrix();


    glPushMatrix();
    glTranslated(-2.0,0.0,-3.0);

    for(double x = 0 ; x <= 1.0 ; x+=0.2){
        glPushMatrix();
        glRotated(30.0,0.0,1.0,0.0);
        glTranslated(x,0.0,0.0);
        drawAStick();
        glPopMatrix();
    }

    glPopMatrix();


    glPushMatrix();
    glTranslated(2.5,0.0,-5.5);

    for(double x = 0 ; x <= 1.0 ; x+=0.2){
        glPushMatrix();
        glRotated(30.0,0.0,1.0,0.0);
        glTranslated(x,0.0,0.0);
        drawAStick();
        glPopMatrix();
    }

    glPopMatrix();

    glPopMatrix();


}