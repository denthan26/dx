#include<iostream>
using namespace std;
class Rectangle {
private:
	double width, height;
	static int count;
public:
	Rectangle();
	Rectangle(double width, double height);
	~Rectangle() {
		count--;
	}
	double getWidth() {
		return width;
	}
	double getHeight() {
		return height;
	}
	void setWidth(double width) {
		this->width = width;
	}
	void setHeight(double height)
	{
		this->height = height;
	}
	double getArea();
	double getPerimeter();
	static void getCount() {
		cout << " Object count = " << count << endl;
	}

};
int Rectangle::count = 0;
Rectangle::Rectangle() :
	width(1.0), height(1.0) {
	count++;
}
Rectangle::Rectangle(double width, double height) :
	width(width), height(height) {
	count++;
}
double Rectangle::getArea()
{
	return height * width;
}
double Rectangle::getPerimeter() {
	return (width + height) * 2;
}
int main()
{
	Rectangle r1;
	cout << r1.getHeight() << " " << r1.getWidth() << endl;
	r1.getCount();
	Rectangle::getCount();
	Rectangle r2;
	cout << r2.getHeight() << " " << r2.getWidth() << endl;
	r2.getCount();
	Rectangle::getCount();
	return 0;
}