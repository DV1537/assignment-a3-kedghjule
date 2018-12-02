#include <iostream>
#include <string>
#include <cmath>
#include "Shape.h"
#include "Point.h"
#include "Line.h"

Line::Line(Point* pnts, int count){
    if(count >= 2){
        points = new Point[2];
        points[0] = pnts[0];
        points[1] = pnts[1];
        p = 2;
    }else{
        p = 0;
    }
}

Line::Line(Point p1, Point p2){
    points = new Point[2];
    points[0] = p1;
    points[1] = p2;
    p = 2;
}

std::string Line::getType(){
    return "Line";
}

double Line::area(){
	return -1;
}

double Line::circumference(){
	return sqrt(pow(points[0].getX() - points[1].getX(),2) + pow(points[0].getY() - points[1].getY(),2))*2;
}

Point Line::position(){
    Point r = Point(0,0);
    double cXS = 0;
    double cYS = 0;
    for (int c = 0; c < p; c++) {
		cXS += points[c].getX();
        cYS += points[c].getY();
	}
    r = Point(cXS / p, cYS / p); 
    return r;
}