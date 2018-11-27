#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include "Shape.h"
#include "Triangle.h"
#include "Line.h"
#include "Polygon.h"

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
        Polygon thisShape(buffer, p);
        cout << thisShape.area() << endl;


    }

    return 0;

}

Point* addToArray(Point* array, int bufferSize, Point value){
    if(array == nullptr){
        //If array is empty, create first slot and add the value
        return new Point[1] {value};
    }else{
        Point* buffer = new Point[bufferSize + 1];
        
        for(int i = 0; i < bufferSize; i++){
            buffer[i] = array[i];
        }
        buffer[bufferSize] = value;
        
        return buffer;
    }
}