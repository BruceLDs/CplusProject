#include<iostream>
using namespace std;
class Data{
public:
	void SetData(int year, int mouth, int data)	{
		this->_year = year;
		this->_mouth = mouth;
		this->_data = data;
	}
	void Display(){
		cout << this->_year << "-" << this->_mouth << "-" << this->_data << endl;
	}
private:
	int _year;
	int _mouth;
	int _data;
};
class Date1
{
public:
	// 1.无参构造函数
	Date1()
	{}
	// 2.带参构造函数
	Date1(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	~Date1(){
		cout << "~Date" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};