#include "Point.h"

Point::Point(double X, double Y){
    x = X;
    y = Y;
}

Point::Point(){
    x = 0;
    y = 0;
}

double Point::getX(){
    return x;
}

double Point::getY(){
    return y;
}

void Point::setX(double X){
    x = X;
}

void Point::setY(double Y){
    y = Y;
}

std::ostream& operator<<(std::ostream& os, const Point& t){
    os << "{x: " << t.x << ",y:" << t.y << "}"; 
    return os;  
}