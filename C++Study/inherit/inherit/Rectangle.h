#pragma once
#include"Shape.h"
class Rectangle:public Shape
{
private:
	double width, height;
public:
	Rectangle();
	Rectangle(double width, double height, string color);
	~Rectangle();
	void setWidth(double width);
	void setHeight(double height);
	double getWidth();
	double getHeight();
	double getArea();
};

