//
// Created by andreimerfu on 28.05.2017.
//

#include <iostream>
#include "BottleView.h"

GLUquadricObj *quadObj;
GLuint objList;

extern double playerX;
extern double playerZ;
extern double alcohol_level;

const double epsilon = 0.2;

bool val = true;


GLfloat ambient_mat_beer[] = {0.19125, 0.0735, 0.0225, };
GLfloat ambient_mat_wine[] = {0.0, 0.0, 0.0, };
GLfloat ambient_mat_vodka[] = {0.0, 0.1, 0.06, };

GLfloat difuse_mat_beer[] = {0.8038, 	0.37048, 	0.0828};
GLfloat difuse_mat_wine[] = {0.5, 	0.0, 	0.0};
GLfloat difuse_mat_vodka[] = {0.0, 	(float)0.50980392, 	(float)0.50980392};

GLfloat specular_mat_beer[] = { 0.256777, 0.137622, 0.086014, };
GLfloat specular_mat_wine[] = { 0.7, 0.6, 0.6, };
GLfloat specular_mat_vodka[] = { (float)0.50196078, (float)0.50196078, (float)0.50196078 };

GLfloat shininess_mat_beer[] = { 0.1 };
GLfloat shininess_mat_wine[] = { 25 };
GLfloat shininess_mat_vodka[] = { 25 };


bottle bottles[MAX_BOTTLES];




void generateBottles(){

    for(int i = 0 ; i < MAX_BOTTLES ; i++){
        bottles[i].y= 0.3;
        bottles[i].x = rand() % 49 + (-29);
        bottles[i].z = rand() % 49 + (-29);
        bottles[i].isVisible = true;
        int value = rand() % 3 + 1;

        if(value == 1)
            bottles[i].type = "BEER";
        else if (value == 2)
            bottles[i].type = "WINE";
        else if (value == 3)
            bottles[i].type = "VODKA";
    }



    objList = glGenLists(1);
    quadObj = gluNewQuadric();

    gluQuadricDrawStyle(quadObj, GLU_FILL); /* flat shaded */
    gluQuadricNormals(quadObj, GLU_FLAT);
    glNewList(objList, GL_COMPILE);
    gluCylinder(quadObj, 0.03, 0.03, 0.06, 15, 5);
    glEndList();

}


void drawABottle(int i){

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);




    if(bottles[i].type == "BEER"){

        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_mat_beer);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, difuse_mat_beer);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_mat_beer);
        glMaterialfv(GL_FRONT, GL_SHININESS, shininess_mat_beer);


    }
    else if(bottles[i].type == "WINE") {

        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_mat_wine);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, difuse_mat_wine);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_mat_wine);
        glMaterialfv(GL_FRONT, GL_SHININESS, shininess_mat_wine);

    }
    else if (bottles[i].type == "VODKA") {
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_mat_vodka);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, difuse_mat_vodka);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_mat_vodka);
        glMaterialfv(GL_FRONT, GL_SHININESS, shininess_mat_vodka);

    }




    glPushMatrix();
    glTranslated(bottles[i].x , bottles[i].y ,bottles[i].z);
    glRotated(90.0,1.0,0.0,0.0);
    glutSolidCylinder(0.05,0.25,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(bottles[i].x , bottles[i].y ,bottles[i].z);
    glutSolidSphere(0.049,10,10);
    glPopMatrix();



    glPushMatrix();
    glTranslated(bottles[i].x , bottles[i].y + 0.04 ,bottles[i].z);
    glRotated(-90.0,1.0,0.0,0.0);
    glCallList(objList);
    glPopMatrix();



    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
}

void drawBottles(){

    for(int i = 0 ; i < MAX_BOTTLES ; ++i){
        if(val){
            std::cout << bottles[i].x << ' ' << bottles[i].z <<std::endl;
            val = false;
        }
        if((playerX >= bottles[i].x - epsilon && playerX <= bottles[i].x + epsilon ) && (
                playerZ >= bottles[i].z - epsilon && playerZ <= bottles[i].z + epsilon)){
             //Conditia ca playerul sa bea bautura*//**//*
            if(bottles[i].type == "BEER" && bottles[i].isVisible)
                alcohol_level += 100.0;
            else if(bottles[i].type == "WINE" && bottles[i].isVisible)
                alcohol_level += 250.0;
            else if(bottles[i].type == "VODKA" && bottles[i].isVisible)
                alcohol_level += 450.0;
            bottles[i].isVisible = false;

        }
        if(bottles[i].isVisible)
            drawABottle(i);
    }
}