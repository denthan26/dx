#pragma once
#include<iostream>
using namespace std;
class Rectan
{
private:
	double width, height;
	static int count;
public:
	Rectan();
	Rectan(double width, double height);
	~Rectan();
	double getWidth();
	double getHeight();
	void setWidth(double width);
	void setHeight(double height);
	double getArea();
	double getPerimeter();
	static void getCount();
};

