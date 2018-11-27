#include <string>
#include <iostream>
#include "Point.h"
#include "Shape.h"
#ifndef LINE_H
#define LINE_H


class Line: public Shape{
    public:
        Line(Point* pnts, int count);
        Line(Point p1, Point p2);
};

#endif