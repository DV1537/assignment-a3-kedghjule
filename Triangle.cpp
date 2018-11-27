#include <iostream>
#include "Shape.h"
#include "Point.h"
#include "Triangle.h"

Triangle::Triangle(Point* pnts, int count){
    if(count >= 3){
        setPoints(new Point[3]);
        getPoints()[0] = pnts[0];
        getPoints()[1] = pnts[1];
        getPoints()[2] = pnts[2];
        setNumberOfVertices(3);
    }else{
        setNumberOfVertices(0);
    }
}

Triangle::Triangle(Point p1, Point p2, Point p3){
    setPoints(new Point[3]);
    getPoints()[0] = p1;
    getPoints()[1] = p2;
    getPoints()[2] = p3;
    setNumberOfVertices(3);
}
