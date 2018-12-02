#include <iostream>
#include <cmath>
#include <fstream>
#include "Shape.h"
#include "Point.h"

//Extended methods

double Shape::distance(Shape& s){
    return sqrt(pow(position().getX() - s.position().getX(),2) + pow(position().getY() - s.position().getY(),2));
}
