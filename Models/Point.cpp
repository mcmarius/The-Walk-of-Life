//
// Created by marius on 3/26/17.
//

#include "Point.h"

Point::Point() {}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {
    v[0]=x;
    v[1]=y;
    v[2]=z;
}

Point::Point(double *v) {
    x=v[0];
    y=v[1];
    z=v[2];
}

Point::operator const double*()  {
    v[0]= (int) x;
    v[1]= (int) y;
    v[2]= (int) z;
    return v;
}

Point::operator double *()  {
    v[0]= (int) x;
    v[1]= (int) y;
    v[2]= (int) z;
    return v;
}

bool Point::operator==(const Point &rhs) const {
    return fabs(x - rhs.x) < epsilon &&
            fabs(y - rhs.y) < epsilon &&
            fabs(z - rhs.z) < epsilon;
}

Point::Point(double x, double z) : x(x), z(z) {
    y = 0;
}
