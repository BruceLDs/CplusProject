#define  _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//class Date{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int days(int year, int month){
//		static int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month == 2)
//			return arr[month] + 1;
//		return arr[month];
//	}
//	int outdays(){
//		if (_month > 12 && _month < 1)
//			return -1;
//		if (_day < 1 && _day > days(_year, _month))
//			return -1;
//		int ret = 0;
//		for (int i = 1; i < _month; i++)
//			ret += days(_year, i);
//		ret += _day;
//		return ret;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main(){
//	int year, month, day;
//	while (cin >> year,
//		cin >> month,
//		cin >> day
//		){
//		Date d(year, month, day);
//		int ret = d.outdays();
//		cout << ret << endl;
//	}
//
//	return 0;
//}

#include <iostream>
using namespace std;
int main()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212,
		243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;
	int sum = 0;
	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += array[month - 2];
		sum += day;
		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)
				|| year % 400 == 0)
			{
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}