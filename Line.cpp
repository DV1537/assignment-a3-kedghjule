#include <iostream>
#include <string>
#include <cmath>
#include "Shape.h"
#include "Point.h"
#include "Line.h"

Line::Line(Point* pnts, int count){
    if(count >= 2){
        setPoints(new Point[2]);
        getPoints()[0] = pnts[0];
        getPoints()[1] = pnts[1];
        setNumberOfVertices(2);
    }else{
        setNumberOfVertices(0);
    }
}

Line::Line(Point p1, Point p2){
    setPoints(new Point[2]);
    getPoints()[0] = p1;
    getPoints()[1] = p2;
    setNumberOfVertices(2);
}