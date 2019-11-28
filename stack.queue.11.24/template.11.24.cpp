#include <string>
#include <iostream>
//#include <array>

using namespace std;

//#define N 100
//非类型模板参数： 作为常量使用
//template <class T, size_t N>
//class array
//{
//private:
//	T _arr[N];
//};
//
//
//void testArray()
//{
//	array<int, 100>  arr;
//	array<int,20>  arr2;
//	array<int, 10000000> arr3;
//	int a = 10;
//	int arr4[10];
//
//}
//
//template <class T>
//bool isBig(T& a, T& b)
//{
//	return a > b;
//}
//
////template<>
////bool isBig<char*>(char*&  a, char*&  b)
////{
////	return strcmp(a, b) > 0;
////}
//
//bool isBig(char* a, char* b)
//{
//	return strcmp(a, b) > 0;
//}
//
//void testString()
//{
//	char* str2 = "456";
//	char* str1 = "123";
//	
//	bool ret = isBig(str1, str2);
//	int a = 1, b = 2;
//	ret = isBig(a, b);
//}
//
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template<>
//class Data<int, int>
//{
//public:
//	Data() { cout << "Data<int, int>" << endl; }
//private:
//	int _d1;
//	int _d2;
//};
//
////偏特化：对部分类型进行特化
//template<class T1>
//class Data<T1, char>
//{
//public:
//	Data() { cout << "Data<T1, char>" << endl; }
//private:
//	int _d1;
//	int _d2;
//};
//
////偏特化： 对模板参数作进一步的限制
//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//
//template<size_t N>
//struct Sum
//{
//	enum { RET = N + Sum<N - 1>::RET};
//};
//
//
//template<>
//struct Sum<1>
//{
//	enum {RET = 1};
//};

