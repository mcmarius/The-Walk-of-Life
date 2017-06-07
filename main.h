//
// Created by marius on 07/06/2017.
//

#ifndef THE_WALK_OF_LIFE_MAIN_H
#define THE_WALK_OF_LIFE_MAIN_H

void initialise();
void reshape(int width, int height);
void processNormalKeys(unsigned char key, int, int);
void processSpecialKeys(int key, int, int);
void draw();

void menu(int);
void createMenu();

void computeBalance();
#endif //THE_WALK_OF_LIFE_MAIN_H
