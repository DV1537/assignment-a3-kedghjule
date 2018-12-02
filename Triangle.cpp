#include <iostream>
#include <cmath>
#include "Shape.h"
#include "Point.h"
#include "Triangle.h"

Triangle::Triangle(){}

Triangle::Triangle(Point* pnts, int count){
    if(count >= 3){
        points = new Point[3];
        points[0] = pnts[0];
        points[1] = pnts[1];
        points[2] = pnts[2];
        p = 3;
    }else{
        p = 0;
    }
}

Triangle::Triangle(Point p1, Point p2, Point p3){
    points = new Point[3];
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    p = 3;
}

std::string Triangle::getType(){
    return "Triangle";
}

double Triangle::area(){

    //We know that a triangle can only be convex, therefore it is unnecessary to call isConvex()

    double a;
    double cSum = 0;
	for (int i = 0; i < p; i++) {
		//Hämta index
		int iXH = 0; //Index ovanför vårt X
		int iXL = 0; //Index under vårt X
		if (i == 0) { //Kolla om vår X-punkt är i början av listan
			iXH = p - 1;
			iXL = 1;
		}else if (i == p - 1) { //Kolla om vår X-punkt är i slutet av listan
			iXH = i - 1;
			iXL = 0;
		}else { //Kolla om vår X-punkt är i mitten av listan
			iXH = i - 1;
			iXL = i + 1;
		}
		double c = points[i].getX() * (points[iXL].getY() - points[iXH].getY()); //Räkna summan av punkten

	    cSum += c; //Lägg till punktens summa till total
	}

	a = 0.5 * fabs(cSum); //Beräkna arean
    a = round(a * 1000); 
    a = a / 1000;

    if(a == 0)
         a = -1;

	return a;
}

bool Triangle::isConvex(){
    return true;
}

double Triangle::circumference(){
	double lSum = 0;
	
    if(p < 3){
        lSum = -1;
    }else{
        for(int l = 0; l < p; l++){
        //Get line segment
        double p1X = points[l].getX();
        double p1Y = points[l].getY();
        double p2X = 0;
        double p2Y = 0;

        //Get end point
        if(l == p - 1){
            p2X = points[0].getX();
            p2Y = points[0].getY();
       }else{
            p2X = points[l+1].getX();
            p2Y = points[l+1].getY();
        }

		lSum += sqrt(pow(p1X-p2X,2) + pow(p1Y-p2Y,2));
	}

    lSum = round(lSum * 1000); 
    lSum = lSum / 1000;

    }
	return lSum;
}

Point Triangle::position(){
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