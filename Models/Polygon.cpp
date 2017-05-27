#include "Polygon.h"

Polygon::Polygon(int n) : n(n) {}

void Polygon::addVertices(Point p1, Point p2, Point p3, Point p4) { //}, Point p5) {
//    switch(n) {
//        case 5:
//            vertices[5] = p5;
//        case 4:
            vertices[4] = p4;
//        case 3:
            vertices[3] = p3;
            vertices[2] = p2;
            vertices[1] = p1;
//        default:
//            break;
//    }
}

Point &Polygon::operator[](int i) {
    return vertices[i];
}

Polygon::Polygon() {
}
