#include <iostream>
#include <cmath>
#include "Shape.h"
#include "Point.h"
#include "Polygon.h"

Polygon::Polygon(){}
Polygon::Polygon(Point* pnts, int count){
    points = pnts;
    p = count;
}

Polygon::~Polygon(){
    delete[] points;
}

std::string Polygon::getType(){
    return "Polygon";
}

double Polygon::area(){
    double a;
    if((!isConvex()) || (p < 3)){
        a = -1;
    }else{
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

    }
	return a;
}

bool Polygon::isConvex(){
    int s = this->p - 2;
    double *cp = new double[s];

    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;

    for (int i = 0; i < s; i++)
    {
        x1 = points[i + 1].getX() - points[i].getX();
        y1 = points[i + 1].getY() - points[i].getY();
        x2 = points[i + 2].getX() - points[i + 1].getX();
        y2 = points[i + 2].getY() - points[i + 1].getY();
        cp[i] = x1 * y2 - y1 * x2;
    }

    bool positive = false;
    bool negative = false;

    for (int i = 0; i < s; i++)
    {
        if (cp[i] > 0){
            positive = true;
        }else{
            negative = true;
        }
    }

    delete[] cp;
    cp = nullptr;

    if (positive && negative){
        return false;
    }else{
        return true;
    }
}

double Polygon::circumference(){
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

Point Polygon::position(){
    Point r = Point(0,0);

    if(isConvex()){
        //Convex
        double cXS = 0;
        double cYS = 0;
        for (int c = 0; c < p; c++) {
	        cXS += points[c].getX();
            cYS += points[c].getY();
	    }
        r = Point(cXS / p, cYS / p);
    }else{
        //Convave
        int iXH = 0, iXL = 0, iYH = 0, iYL = 0;
        
        for(int i = 0; i < p; i++){
            if (points[i].getX() > points[iXH].getX())
                iXH = i;
            if (points[i].getX() < points[iXL].getX())
                iXL = i;
            if (points[i].getY() > points[iYH].getY())
                iYH = i;
            if (points[i].getY() < points[iYL].getY())
                iYL = i;
        }

        r = Point(fabs(points[iXH].getX() + points[iXL].getX()) / 2, fabs(points[iYH].getY() + points[iYL].getY()) / 2);
    }
    return r;
}

void Polygon::operator=(const Polygon &rhs)
{
    p = rhs.p;
    points = new Point[rhs.p];
    for (int k = 0; k < rhs.p; k++)
        points[k] = rhs.points[k];
}

Polygon operator+(Polygon a, Polygon b){
    Polygon s = Polygon();
    s.p = a.p + b.p;
    
    Point* buffer = new Point[s.p];
    int aC = 0, bC = 0;

    while(aC < a.p ){
        buffer[aC] = a.points[aC];
        aC++;
    }
    while(bC < b.p){
        buffer[aC + bC] = b.points[bC];
        bC++;
    }

    s.points = buffer;
    return s;
}
Polygon operator+(Polygon a, Point b){
    Polygon s = Polygon();
    s.p = a.p + 1;
    
    Point* buffer = new Point[s.p];
    for(int i = 0; i < a.p; i++){
        buffer[i] = a.points[i];
    }
    buffer[a.p] = b;

    s.points = buffer;
    return s;
}
std::ostream &operator<<(std::ostream& out, Polygon s){
    for(int p = 0; p < s.p; p++){
        out << "{" << s.points[p].getX() << "," << s.points[p].getY() << "} ";
    }
    out << std::endl;
    return out;
}