#include "Rectan.h"
#include<iostream>
using namespace std;
int Rectan::count = 0;
Rectan::Rectan() :
	width(1.0), height(1.0) {
	count++;
	cout << "default 构造函数" << endl;
}
Rectan::Rectan(double width, double height) :
	width(width), height(height) {
	count++;
	cout << "构造函数" << endl;
}
Rectan::~Rectan() {
	count--;
	cout << "销毁" << endl;
}
double Rectan::getArea()
{
	return height * width;
}
double Rectan::getPerimeter() {
	return (width + height) * 2;
}
double Rectan::getWidth() {
	return width;
}
double Rectan::getHeight() {
	return height;
}
void Rectan::setWidth(double width) {
	this->width = width;
}
void Rectan::setHeight(double height)
{
	this->height = height;
}
void Rectan::getCount() {
	cout << " Object count = " << count << endl;
}