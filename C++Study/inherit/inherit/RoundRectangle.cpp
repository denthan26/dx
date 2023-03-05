#include "RoundRectangle.h"
RoundRectangle::RoundRectangle() {
	this->roundRadius = 1;
	cout << "RoundRectangle's default constructor" << endl;
}
RoundRectangle::RoundRectangle(double width, double height, string color, double roundRadius) :
	Rectangle(width, height,color) {
	this->roundRadius = roundRadius;
}
RoundRectangle::~RoundRectangle() {
	cout << "RoundRectangle's distructor" << endl;
}
void RoundRectangle::setRoundRadius(double roundRadius) {
	this->roundRadius = roundRadius;
}
double RoundRectangle::getRoundRadius() {
	return this->roundRadius;
}
double RoundRectangle::getArea() {
	double a = this->getHeight();
	double b = this->getWidth();
	return a * b - C * this->roundRadius * this->roundRadius;
}
