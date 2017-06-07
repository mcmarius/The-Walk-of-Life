#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "GameLogic.h"

void initHomeCollisions();
void initHomeFenceCollisions();

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
            if(inside) {
                std::cout<<"Din pacate cetateanul s-a imbatat si nu si-a putut indeplini misiunea!"<<std::endl;
                exit(0);
                return true;
            }
            secondList.pop_back();
        }
    }
    return false;
}

void initCollisions() {
    initHomeCollisions();
    initHomeFenceCollisions();
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

void initHomeCollisions() {
    Polygon houseFrontWallLeft(4), houseFrontWallRight(4),
            houseLeftWall(4), houseRightWall(4), houseBackWall(4);//, houseDoor(4);

    houseFrontWallLeft.addVertices(Point(0.256017, -5.0156843),
                                   Point(-1.218602, -4.110973),
                                   Point(-1.390987, -4.410864),
                                   Point(0.073493, -5.185703));
    addPolygon(houseFrontWallLeft);

    houseFrontWallRight.addVertices(Point(0.748597, -5.294455),
                                    Point(0.600000, -5.500000),
                                    Point(1.975371, -6.388843),
                                    Point(2.134902, -6.103373));
    addPolygon(houseFrontWallRight);

    houseLeftWall.addVertices(Point(-1.359682, -4.109242),
                              Point(-2.497730, -6.018492),
                              Point(-2.274956, -6.037777),
                              Point(-1.150000, -4.250000));
    addPolygon(houseLeftWall);

    houseBackWall.addVertices(Point(-2.036300, -5.764039),
                              Point(-2.468760, -6.023538),
                              Point(1.079471, -8.143529),
                              Point(1.393084, -7.832015));
    addPolygon(houseBackWall);

    houseRightWall.addVertices(Point(2.281443, -6.071438),
                               Point(1.827604, -6.306402),
                               Point(1.228241, -7.713798),
                               Point(1.280380, -7.991794));
    addPolygon(houseRightWall);



    /*if(lockedHouse) {
        houseDoor.addVertices(Point(0.100000, -4.900000),
                              Point(0.100000, -5.200000),
                              Point(0.600000, -5.500000),
                              Point(0.700000, -5.300000));
        addPolygon(houseDoor);
    }*/
}

void initHomeFenceCollisions() {
    Polygon /*houseFrontFenceLeft(4), houseFrontFenceRight(4),*/
            houseLeftFence(4), houseRightFence(4), houseBackFence(4),road1(4),road2(4),road3(4);

    /*houseFrontFenceLeft.addVertices(Point(-2.085163, -2.827030),
                               Point(-4.585800, -6.983974),
                               Point(-4.107269, -7.160065),
                               Point(-1.744153, -3.036105));
    addPolygon(houseFrontFenceLeft);

    houseFrontFenceRight.addVertices(Point(-2.085163, -2.827030),
                               Point(-4.585800, -6.983974),
                               Point(-4.107269, -7.160065),
                               Point(-1.744153, -3.036105));
    addPolygon(houseFrontFenceRight);*/

    houseLeftFence.addVertices(Point(-2.085163, -2.827030),
                               Point(-4.585800, -6.983974),
                               Point(-4.107269, -7.160065),
                               Point(-1.744153, -3.036105));
    addPolygon(houseLeftFence);

    houseBackFence.addVertices(Point(-4.610446, -7.167594),
                               Point(1.159707, -10.410331),
                               Point(1.408123, -10.035135),
                               Point(-3.968479, -6.946099));
    addPolygon(houseBackFence);

    houseRightFence.addVertices(Point(1.033878, -9.813990),
                               Point(1.420477, -9.957314),
                               Point(3.770231, -5.991377),
                               Point(3.357564, -5.709056));
    addPolygon(houseRightFence);

    road1.addVertices(Point(1.089393,-2.396882),
                    Point(1.267401,-2.547754),
                    Point(48.291836,78.982340),
                    Point(48.056887,78.993308));
    addPolygon(road1);

    road2.addVertices(Point(2.304480,-3.118159),
                      Point(2.457216,-3.173652),
                      Point(49.585241,78.222507),
                      Point(49.303429,78.325376));
    addPolygon(road2);

    road3.addVertices(Point(48.407444,79.376009),
                      Point(48.251677,79.007585),
                      Point(49.502220,78.370293),
                      Point(49.612350,78.679584));
    addPolygon(road3);
}
