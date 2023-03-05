#pragma once
#include"Rectangle.h"
const double C = 0.86;
class RoundRectangle:public Rectangle
{
private:
	double roundRadius;
public:
	RoundRectangle();
	RoundRectangle(double width, double height, string color, double roundRadius);
	~RoundRectangle();
	void setRoundRadius(double roundRadius);
	double getRoundRadius();
	double getArea();
};

