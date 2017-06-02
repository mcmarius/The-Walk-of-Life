#ifndef THE_WALK_OF_LIFE_HOMEVIEW_H
#define THE_WALK_OF_LIFE_HOMEVIEW_H

#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <GL/freeglut.h>
#include "../Utility/imageloader.h"






    void drawAHome(void);
    void drawAnotherHome(void);
    void loadTextureOfHouse(void);
    GLuint loadTexture(Image*);
    void write(const char*);



#endif //THE_WALK_OF_LIFE_HOMEVIEW_H
