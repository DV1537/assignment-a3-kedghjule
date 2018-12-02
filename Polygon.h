#include <string>
#include <iostream>
#include "Point.h"
#include "Shape.h"
#ifndef POLYGON_H
#define POLYGON_H


class Polygon: virtual Shape{
    public:
        Polygon();
        Polygon(Point* pnts, int count);
        std::string getType();
        double area();
        bool isConvex();
        double circumference();
        Point position();

        friend Polygon operator+(Polygon a, Polygon b);
        friend Polygon operator+(Polygon a, Point b);
        friend std::ostream &operator<<(std::ostream &out, Polygon s);
    private:
        int p;
        Point* points;
};

#endif