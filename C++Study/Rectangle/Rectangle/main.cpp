#include "Rectan.h"
#include<iostream>
using namespace std;

int main()
{
	Rectan rect[3] = { Rectan(3,4),Rectan(7,6),Rectan(5,6) };
	Rectan::getCount();
	for (int i = 0; i < 3; i++)
	{
		cout << rect[i].getWidth() << endl;
		cout<<rect[i].getHeight() << endl;
		cout<<rect[i].getArea() << endl;
		cout<<rect[i].getPerimeter() << endl;
	}
	Rectan* prectangle[3];
	for (int i = 0; i < 3; i++)
	{
		prectangle[i] = new Rectan;
	}
	for (int i = 0; i < 3; i++) {
		cout << prectangle[i]->getWidth() << endl;
		cout<<prectangle[i]->getHeight() << endl;
		cout<<prectangle[i]->getArea() << endl;
		cout<<prectangle[i]->getPerimeter() << endl;
	}
	Rectan::getCount();
	for (int i = 0; i < 3; i++)
	{
		delete prectangle[i];
	}

	Rectan drect[3] = { Rectan(3,4),Rectan(7,6),Rectan(5,6) };
	Rectan::getCount();
	for (int i = 0; i < 3; i++)
	{
		cout << drect[i].getWidth() << endl;
		cout << drect[i].getHeight() << endl;
		cout << drect[i].getArea() << endl;
		cout << drect[i].getPerimeter() << endl;
	}
	return 0;
}