TestRule: main.cpp
	g++ main.cpp Shape.h Shape.cpp Triangle.h Triangle.cpp Line.h Line.cpp Polygon.h Polygon.cpp Point.h Point.cpp -o main.exe -static-libgcc -static-libstdc++