#include<iostream>
using namespace std;

class Clock {
private:
	int hour, minute, second;
public:
	Clock();
	~Clock();
	Clock(int newH, int newM, int newS);
	void setTime(int newH, int newM, int newS);
	void showTime();
};
Clock::Clock() :
	hour(1), minute(1), second(1) {

}
Clock::~Clock() {
	cout << "clock��ʧ" << endl;
}
Clock::Clock(int newH, int newM, int newS) :
	hour(newH), minute(newM), second(newS) {

}
void Clock::setTime(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
}
void Clock::showTime() {
	cout << "��ǰʱ��Ϊ��";
	cout << hour << ":" << minute << ":" << second << endl;
}
int main()
{
	Clock myclock1;
	Clock myclock2(8, 3, 30);
	cout << "��һ��ʱ��Ϊ:" << endl;
	myclock1.showTime();
	cout << "�ڶ���ʱ��Ϊ:" << endl;
	myclock2.showTime();
	return 0;
}