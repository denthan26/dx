#include<iostream>
#include <iomanip>
using namespace std;
const double PI = 3.14;
void sumArea(double* radious, int n);
int main()
{
	int n;
	cout << "输入一个整数，表示数组大小:";
	cin >> n;
	double* radius = new double[n];
	cout << "输入" << n << "个圆半径:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> radius[i];
	}
	sumArea(radius, n);
	return 0;
}
void sumArea(double* radious, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += PI * radious[i] * radious[i];
	}

	cout << '\n' << sum << endl;
	cout << fixed << setprecision(5) << sum;
}