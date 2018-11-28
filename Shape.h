#include <string>
#include <iostream>
#include "Point.h"
#ifndef SHAPE_H
#define SHAPE_H


class Shape{
    public:
        //Constructors
        Shape();
        Shape(Point* pnts, int count);
        Shape(std::string path);
        
        //Extended methods
        std::string getType();
        double area();
        double circumference();
        Point position();
        bool isConvex();
        double distance(const Shape s);

        //Getters and setters
        Point* getPoints();
        void setPoints(Point* pnts);
        int getNumberOfVertices();
        void setNumberOfVertices(int v);

        //Operator overloading
        Shape& operator=(const Shape &s);
        friend Shape operator+(Shape a, Shape b);
        friend std::ostream &operator<<(std::ostream &out, Shape s);
    private:
        int p;
        Point* points;
};

#endif