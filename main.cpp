#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include "Shape.h"
#include "Triangle.h"
#include "Line.h"
#include "Polygon.h"
#include "memgmt.h" //Used to dynamically manage memory in arrays

using namespace std;

Point* addToArray(Point* array, int bufferSize, Point value);

int main(int argc, const char * argv[])
{
    double a = 0;
    int c = 1;
    int p = 0;
	Point* buffer = { 0 };
    Point cPnt;

    ifstream myReadFile;
    myReadFile.open(argv[1]);

    if(myReadFile.is_open() == false || argc < 2){
        return EXIT_FAILURE;
    }else{
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


        //Usage of classes
        Shape shapeOne("./tests/poly1.txt");
        Shape shapeTwo("./tests/poly2.txt");
        Shape shapeThree("./tests/poly3.txt");


        cout << "1: " << shapeOne << endl;
        cout << "2: " << shapeTwo << endl;
        cout << "3: " << shapeThree << endl;

        Shape hello = shapeOne + shapeTwo;

        cout << hello.area() << endl;

    }

    return 0;

}