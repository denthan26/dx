#pragma once
#include<iostream>
using namespace std;
class Shape
{
private:
	string color;
public:
	Shape();
	Shape(string color);
	~Shape();
	void setColor(string color);
	string getColor();
	double getArea();
};

