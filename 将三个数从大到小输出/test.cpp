#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;

int main(){
	int a = 3, b = 2, c = 6;
	list<int> l;
	l.push_back(a);
	if (b <= a)
		l.push_back(b);
	else
		l.push_front(b);
	if (c <= l.back())
		cout << l.front() << "," << l.back() << "," << c << endl;
	else{
		if (c < l.front())
			cout << l.front() << "," << c << ","<< l.back() << endl;
		else
			cout << c <<","<< l.front() << "," << l.back() << endl;
	}
	return 0;
}
