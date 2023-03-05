#include "Circle.h"
Circle::Circle() {
	this->radius = 0;
	cout << "Circle's default constructor" << endl;
}
Circle::Circle(double radius, string color) :Shape(color) {
	this->radius = radius;
	cout << "Circle's constructor" << endl;
}
Circle::~Circle() {
	cout << "Circle's distructor" << endl;
}
void Circle::setRadius(double radius) {
	this->radius = radius;
}
double Circle::getRadius() {
	return this->radius;
}
double Circle::getArea() {
	return PI * this->radius * this->radius;
}
