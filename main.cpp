#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>

#include "Shape.h"
#include "Triangle.h"
#include "Line.h"
#include "Polygon.h"

using namespace std;

Point* addToArray(Point* array, int bufferSize, Point value);

int main(int argc, const char * argv[])
{
    double a = 0;
    int c = 1; //Sub buffer in-time count
    int p = 0; //Sub buffer count
    int s = 0; //Total buffer count
    const int numberOfShapes = 2; //Number of shapes to load

	Polygon* newShape = new Polygon[numberOfShapes];

    Point cPnt;

    ifstream myReadFile;
    myReadFile.open(argv[1]);

    if(myReadFile.is_open() == false || argc < 2){
        return EXIT_FAILURE;
    }else{
        std::string line;

        while (std::getline(myReadFile, line))
        {   
            Point* subBuffer = nullptr;
            p = 0;

            std::istringstream iss (line);

            while(iss >> a){
                
                a = (int)(a * 1000 + .5); 
                a = a / 1000;

                if (c % 2 == 0) {
			        //Append to Y
                    cPnt.setY(a);
			        subBuffer = addToArray(subBuffer, p, cPnt);
			        p++;

		        }else {
			        //Append to X
			        cPnt = Point(a,0);
		        }
		        c++;
            }

            Polygon thisShape = Polygon(subBuffer, p);
            newShape[s] = thisShape;
            s++;
        }    
        myReadFile.close();

        Polygon p1 = newShape[0];
        Polygon p2 = newShape[1];


        //Usage of classes and testing
        
        
        Polygon tp1 = p1 + Point(23,23);
        Polygon tp2 = p1 + p2;
        

        cout << "Area: " << tp2.area() << endl;
        cout << tp2 << endl;



        //Clean up memory
        delete[] newShape;
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
