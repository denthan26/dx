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
	cout << "clock消失" << endl;
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
	cout << "当前时间为：";
	cout << hour << ":" << minute << ":" << second << endl;
}
int main()
{
	Clock myclock1;
	Clock myclock2(8, 3, 30);
	cout << "第一个时间为:" << endl;
	myclock1.showTime();
	cout << "第二个时间为:" << endl;
	myclock2.showTime();
	return 0;
}