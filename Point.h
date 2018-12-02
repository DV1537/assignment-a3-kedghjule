#include <iostream>
#ifndef POINT_H
#define POINT_H


class Point{
    public:
        Point(double X, double Y);
        Point();
        double getX();
        double getY();
        void setX(double X);
        void setY(double Y);

        void operator=(const Point &rhs);
        friend std::ostream& operator<<(std::ostream& os, const Point& t);
    private:
        double x;
        double y;
};

#endif