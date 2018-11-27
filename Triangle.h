#include <string>
#include <iostream>
#include "Point.h"
#include "Shape.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle: public Shape{
    public:
        Triangle(Point* pnts, int count);
        Triangle(Point p1, Point p2, Point p3);
};

#endif