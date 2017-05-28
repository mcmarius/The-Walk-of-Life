#ifndef THE_WALK_OF_LIFE_POLYGON_H
#define THE_WALK_OF_LIFE_POLYGON_H

#include "Point.h"

struct Polygon {
    Polygon();
    Point vertices[11];
    int n;

    Polygon(int n);
    void addVertices(Point p1, Point p2, Point p3, Point p4);
    Point& operator[](int i);
};

#endif //THE_WALK_OF_LIFE_POLYGON_H
