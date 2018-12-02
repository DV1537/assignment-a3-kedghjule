#include <string>
#include <iostream>
#include "Point.h"
#ifndef SHAPE_H
#define SHAPE_H


class Shape{
    public:
        //Extended methods
        virtual std::string getType() = 0;
        virtual double area() = 0;
        virtual double circumference() = 0;
        virtual Point position() = 0;
        bool isConvex();
        double distance(Shape& s);
};

#endif