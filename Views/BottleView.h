//
// Created by andreimerfu on 28.05.2017.
//

#ifndef THE_WALK_OF_LIFE_BOTTLEVIEW_H
#define THE_WALK_OF_LIFE_BOTTLEVIEW_H


#include <GL/freeglut.h>
#include <string>

#define MAX_BOTTLES 15



struct bottle{

    std::string type;
    double x;
    double y ;
    double z;
    bool isVisible;

};




void drawABottle(int);
void generateBottles(void);
void drawBottles(void);

#endif //THE_WALK_OF_LIFE_BOTTLEVIEW_H
