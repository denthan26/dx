#include "Shape.h"
Shape::Shape() {
	this->color = "white";
	cout << "Shape's default constructor" << endl;
}
Shape::Shape(string color) {
	this->color = color;
	cout << "Shape's constructor" << endl;
}
Shape::~Shape() {
	cout << "Shape's distructor" << endl;
}
void Shape::setColor(string color) {
	this->color = color;
}
string Shape::getColor() {
	return this->color;
}
double Shape::getArea() {
	return 0;
}
