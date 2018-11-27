#include <iostream>
#include "Shape.h"
#include "Point.h"
#include "Polygon.h"

Polygon::Polygon(Point* pnts, int count){
    setPoints(pnts);
    setNumberOfVertices(count);
}