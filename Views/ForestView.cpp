//
// Created by andreimerfu on 28.05.2017.
//

#include "ForestView.h"


GLfloat ambiente[] = {0.0,  	0.05, 0.0 };
GLfloat difuse[] = {0.4, 	0.5, 0.4};
GLfloat speculare[] = { 0.04, 0.7, 0.04, 1.0 };
GLfloat shininess[] = { .078125 };


double trans_x[200] ;
double trans_z[200] ;

void initialize_trans_x_y(){
    for(int i = 0 ; i < 200 ; i ++){
        trans_x[i] = rand() % 49 + (-29);
        trans_z[i] = rand() % 49 + (-29);
    }
}


void drawATree(){


}

void drawAFir(){
    //glColor3d(0.0,0.5,0.0);


    glColor3d(0.8,0.5,0.05);

    glPushMatrix();
    glRotated(-90.0,1.0,0.0,0.0);
    glutSolidCylinder(0.1,0.5,10,10);

    glPopMatrix();

    glPushMatrix();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, speculare);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess[0] * 128.0);


    glPushMatrix();


    glRotated(-90.0,1.0,0.0,0.0);
    glTranslated(0.0,0.0,1.5);
    glutSolidCone(0.5,0.8,15,15);

    glPopMatrix();


    glPushMatrix();


    glRotated(-90.0,1.0,0.0,0.0);
    glTranslated(0.0,0.0,1.0);
    glutSolidCone(0.5,1.0,15,15);

    glPopMatrix();


    glPushMatrix();


    glRotated(-90.0,1.0,0.0,0.0);
    glTranslated(0.0,0.0,0.5);
    glutSolidCone(0.5,1.0,15,15);

    glPopMatrix();




    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);

    glPopMatrix();

}

void drawAForest(){
    for(int i = 0 ; i < 200 ; i ++)
    {

        glPushMatrix();
        if(trans_z[i] < -6 || trans_z[i] > 4)
            glTranslated(trans_x[i],0.0 ,trans_z[i]);

        drawAFir();

        glPopMatrix();
    }
}