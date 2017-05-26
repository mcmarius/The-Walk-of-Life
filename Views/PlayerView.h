#ifndef THE_WALK_OF_LIFE_PLAYERVIEW_H
#define THE_WALK_OF_LIFE_PLAYERVIEW_H

#include <cmath>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL.h>
#include <string>

void loadPlayerTexture(const std::string nume, GLuint &id);
void drawPlayer();

#endif //THE_WALK_OF_LIFE_PLAYERVIEW_H
