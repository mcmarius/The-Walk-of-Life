//
// Created by marius on 3/26/17.
//

#ifndef LAB5_POINT_H
#define LAB5_POINT_H

#include <cmath>

double const epsilon = 1e-3;

struct Point {
    double v[3];
    double x, y, z;

    Point();
    Point(double x, double y, double z);
    Point(double x, double z);
    Point(double*);

    operator const double*();
    operator double *();

    bool operator==(const Point &rhs) const;

};


#endif //LAB5_POINT_H
