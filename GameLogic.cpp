#include <cstdio>
#include "GameLogic.h"

bool anyCollisions(double x, double y) {
    if(!initialisedCollisions) {
        initCollisions();
        initialisedCollisions = true;
    }
    Point point(x, y);
    Polygon p;
    std::list<Polygon> secondList(polygonList);
    if(!secondList.empty()) {
        while(!secondList.empty()) {
            p = secondList.back();
            /*for(int i = 1; i < p.n; ++i) {
                if(turn(p[i], p[i + 1], point) < 0)
                    break;
            }*/
            bool inside = turn(p[4], p[1], point) > 0 &&
                          turn(p[1], p[2], point) > 0 &&
                          turn(p[2], p[3], point) > 0 &&
                          turn(p[3], p[4], point) > 0;
            if(inside)
                return true;
            secondList.pop_back();
        }
    }
    return false;
}

void initCollisions() {
    Polygon houseFrontWallLeft(4), houseFrontWallRight(4), houseLeftWall(4);//, houseRightWall(4), houseBackWall(4);

    houseFrontWallLeft.addVertices(Point(0.256017, -5.0156843),
                                   Point(-1.218602, -4.110973),
                                   Point(-1.390987, -4.410864),
                                   Point(0.073493, -5.185703));

    houseFrontWallRight.addVertices(Point(0.748597, -5.294455),
                                    Point(0.600000, -5.500000),
                                    Point(1.975371, -6.388843),
                                    Point(2.134902, -6.103373));
    houseLeftWall.addVertices(Point(-1.359682, -4.109242),
                              Point(-2.497730, -6.018492),
                              Point(-2.274956, -6.037777),
                              Point(-1.150000, -4.250000));
//    houseRightWall.addVertices(Point(), Point(), Point(), Point());
//    houseBackWall.addVertices(Point(), Point(), Point(), Point());

    addPolygon(houseFrontWallLeft);
    addPolygon(houseFrontWallRight);
    addPolygon(houseLeftWall);
//    addPolygon(houseRightWall);
//    addPolygon(houseBackWall);
}

void addPolygon(Polygon &p) {
    polygonList.push_back(p);
}

double turn(Point &p1, Point &p2, Point &p3) {
    return turn(p1.x, p1.z, p2.x, p2.z, p3.x, p3.z);
}

double turn(double x1, double y1, double x2, double y2, double x3, double y3) {     // returns > 0 if (x3, y3) is to
    return x3 * y1 + x1 * y2 + y3 * x2 - y1 * x2 - y3 * x1 - x3 * y2;   // the left of the (x1, y1), (x2, y2) line
}

