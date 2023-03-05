#include"Shape.h"
#include"Circle.h"
#include"Rectangle.h"
#include"RoundRectangle.h"
using namespace std;

int main()
{
	cout << "Shape" << endl;
	Shape shape1;
	cout << "shape1's area = " << shape1.getArea() << endl;
	cout << "shape1's color = " << shape1.getColor() << endl;
	Shape shape2("red");
	cout << "shape2's area = " << shape2.getArea() << endl;
	cout << "shape2's color = " << shape2.getColor() << endl;
	cout << "===================================" << endl;
	cout << "Circle" << endl;
	Circle c1;
	cout << "c1's areaq = " << c1.getArea() << endl;
	cout << "c1's color = " << c1.getColor() << endl;
	Circle c2(2, "black");
	cout << "c2's areaq = " << c2.getArea() << endl;
	cout << "c2's color = " << c2.getColor() << endl;
	cout<< "===================================" << endl;
	cout << "Rectangle" << endl;
	Rectangle rect1;
	cout << "rect1's area = " << rect1.getArea() << endl;
	cout << "rect1's color = " << rect1.getColor() << endl;
	Rectangle rect2(2, 5, "pink");
	cout << "rect2's area = " << rect2.getArea() << endl;
	cout << "rect2's color = " << rect2.getColor() << endl;
	cout << "===================================" << endl;
	cout << "RoundRectangle" << endl;
	RoundRectangle round1;
	cout << "round1's area = " << round1.getArea() << endl;
	cout << "round1's color = " << round1.getColor() << endl;
	RoundRectangle round2(4, 3, "silver", 3);
	cout << "round2's area = " << round2.getArea() << endl;
	cout << "round2's color = " << round2.getColor() << endl;
	cout << "===================================" << endl;
	return 0;
}