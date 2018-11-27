#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "Shape.h"
#include "Point.h"
#include "memgmt.h" //Used to dynamically manage memory in arrays

using namespace std;

//Constructors

Shape::Shape(){
    p = 3;
}

Shape::Shape(Point* pnts, int count){
    points = pnts;
    p = count;
}

Shape::Shape(std::string path){
    ifstream myReadFile;
    myReadFile.open(path);

    double a = 0;
    int c = 1;
    int p = 0;
	Point* buffer = { 0 };
    Point cPnt;

    while (myReadFile >> a)
    {   
        a = (int)(a * 1000 + .5); 
        a = a / 1000;

        if (c % 2 == 0) {
			//Append to Y
            cPnt.setY(a);
			buffer = addToArray(buffer, p, cPnt);
			p++;

		}else {
			//Append to X
			cPnt = Point(a,0);
		}
		c++;
    }    
    myReadFile.close();
    
    this->points = buffer;
    this->p = p;
}

//Extended methods

string Shape::getType(){
    string s = "Undefined";
    switch(getNumberOfVertices()){
        case 0:
            s = "Undefined";
            break;
        case 1:
            s = "Point";
            break;
        case 2:
            s = "Line";
            break;
        case 3:
            s = "Triangle";
            break;
        default:
            s = "Polygon";
            break;
    }
    return s;
}

double Shape::area(){
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

	    a = 0.5 * abs(cSum); //Beräkna arean
        a = round(a * 1000); 
        a = a / 1000;

        if(a == 0)
            a = -1;

    }
	return a;
}

bool Shape::isConvex(){ //https://pastebin.com/4ZnHu22Z old code
    bool convex = true;

    //Beräkna centrumpunkt i polygon med medelvärde
    Point center = position();

    //Kontrollera alla punkter
    for (int i = 0; i < p; i++) {
		//Hämta närliggande index
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
		
        //Fastställ alla punkter i triangeln den utvalda triangeln
        //Grannpunkt
        double aX = points[iXH].getX(); 
        double aY = points[iXH].getY();
        //Denna punkt
        double bX = points[i].getX();
        double bY = points[i].getY();
        //Grannpunkt
        double cX = points[iXL].getX();
		double cY = points[iXL].getY();

        //Medelpunkt i triangeln
        double mX = (aX + cX + bX) / 3;
        double mY = (aY + cY + bY) / 3;
        
        double lOut = sqrt(pow(center.getX()-mX,2)+pow(center.getY()-mY,2)); //Längd från medelpunkt i triangeln till mitten
        double pOrigin = sqrt(pow(center.getX()-bX,2)+pow(center.getY()-bY,2)); //Längd från denna punkt till mitten

        if(lOut > pOrigin)
            convex = false;
	}
    return convex;
}

Point Shape::position(){
    double cXS = 0;
    double cYS = 0;
    for (int c = 0; c < p; c++) {
		cXS += points[c].getX();
        cYS += points[c].getY();
	}

	return Point(cXS / p, cYS / p);
}

double Shape::circumference(){
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

double Shape::distance(Shape s){
    return sqrt(pow(position().getX() - s.position().getX(),2) + pow(position().getY() - s.position().getY(),2));
}

//Getters and setters

Point* Shape::getPoints(){
    return this->points;
}
void Shape::setPoints(Point* pnts){
    this->points = pnts;
}
int Shape::getNumberOfVertices(){
    return this->p;
}
void Shape::setNumberOfVertices(int v){
    this->p = v;
}

//Operator overloading
Shape& Shape::operator=(const Shape &s){
    this->p = s.p;

    Point* pnts = new Point[s.p];
    for(int i = 0; i < s.p; i++){
        pnts[i] = s.points[i];
    }
    
    delete[] this->points;
    this->points = nullptr;
    this->points = pnts;

    return *this;
}

Shape operator+(Shape a, Shape b){
    Shape s = Shape();
    s.p = (a.p + b.p);
    
    Point* buffer = new Point[s.p];
    int aC = 0, bC = 0;

    while(aC < a.p){
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

std::ostream &operator<<(std::ostream& out, Shape s){
    for(int p = 0; p < s.getNumberOfVertices(); p++){
        out << "{" << s.getPoints()[p].getX() << "," << s.getPoints()[p].getY() << "} ";
    }
    out << endl;
    return out;
}