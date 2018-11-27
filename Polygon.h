#include <string>
#include <iostream>
#include "Point.h"
#include "Shape.h"
#ifndef POLYGON_H
#define POLYGON_H


class Polygon: public Shape{
    public:
        Polygon(Point* pnts, int count);
};

#endif