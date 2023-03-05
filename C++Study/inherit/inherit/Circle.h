#pragma once
#include"Shape.h"
const double PI = 3.14;
class Circle:public Shape
{
private:
	double radius;
public:
	Circle();
	Circle(double radius, string color);
	~Circle();
	void setRadius(double radius);
	double getRadius();
	double getArea();
};

