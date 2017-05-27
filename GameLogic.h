#ifndef THE_WALK_OF_LIFE_GAMELOGIC_H
#define THE_WALK_OF_LIFE_GAMELOGIC_H

#include "Models/Polygon.h"
#include <list>

extern std::list<struct Polygon> polygonList;
extern bool initialisedCollisions;
extern const double PI;

bool anyCollisions(double x, double y);
void initCollisions();
void addPolygon(struct Polygon &);
double turn(Point&, Point&, Point&);
double turn(double x1, double y1, double x2, double y2, double x3, double y3);
#endif //THE_WALK_OF_LIFE_GAMELOGIC_H
