#include <string>
#include <iostream>
#include "Point.h"
#include "Shape.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle: virtual Shape{
    public:
        Triangle();
        Triangle(Point* pnts, int count);
        Triangle(Point p1, Point p2, Point p3);
        std::string getType();
        double area();
        bool isConvex();
        double circumference();
        Point position();
    private:
        int p;
        Point* points;
};

#endif