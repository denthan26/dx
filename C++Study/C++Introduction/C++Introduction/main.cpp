#include<iostream>
using namespace std;
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int add(int x = 5, int y = 6)
{
	return x + y;
}
int main()
{
	// cin cout
	int x;
	cin >> x;
	cout << "x=" << x << endl;

	// new delete
	int* arr = new int[100];
	delete[] arr;

	// ����
	int m = 5, n = 9;
	cout << "m=" << m << " n=" << n << endl;
	swap(m, n);
	cout << "m=" << m << " n=" << n << endl;

	// ��������

	// ����Ĭ��ֵ�ĺ�������
	add(10, 20);
	add(10);
	add();
	return 0;
}