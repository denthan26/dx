#include "Rectangle.h"
Rectangle::Rectangle() {
	this->width = 1;
	this->height = 1;
	cout << "Rectangle's default constructor" << endl;
}
Rectangle::Rectangle(double width, double height, string color) :Shape(color) {
	this->width = width;
	this->height = height;
	cout << "Rectangle's constructor" << endl;
}
Rectangle::~Rectangle() {
	cout << "Rectangle's distructor" << endl;
}
void Rectangle::setWidth(double width) {
	this->width = width;
}
void Rectangle::setHeight(double height) {
	this->height = height;
}
double Rectangle::getWidth() {
	return this->width;
}
double Rectangle::getHeight() {
	return this->height;
}
double Rectangle::getArea() {
	return this->width * this->height;
}
