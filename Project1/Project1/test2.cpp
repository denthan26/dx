#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;

int main() {
	set <char> s;
	s.insert('a');
	s.insert('b');
	s.insert('c');
	s.insert('d');
	cout << (s.find('a') == s.end()) << endl;
	cout << (s.find('b') == s.end()) << endl;
	cout << (s.find('c') == s.end()) << endl;
	cout << (s.find('d') == s.end()) << endl;
	cout << (s.find('e') == s.end()) << endl;
	s.erase('a');
	cout << endl;
	cout << (s.find('a') == s.end()) << endl;
	string str = "abc";
	cout << str.length() << endl;
	return 0;
}




// 以下的为算法设计内容
int main1() {
	vector<int> myv;
	vector<int>::iterator it;
	myv.push_back(1);
	it = myv.begin();
	myv.insert(it, 2);
	myv.push_back(3);
	myv.push_back(4);
	it = myv.end();
	it--;
	myv.erase(it);
	for (it = myv.begin(); it != myv.end(); ++it) {
		printf("%d ", *it);
	}
	return 0;
}