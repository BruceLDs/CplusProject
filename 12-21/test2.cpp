#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int Devide(int a, int b){
//	if (b == 0){
//		throw string("Devide by zero");
//	}
//	return a / b;
//}
//
//void fun()
//{
//	int a, b;
//	cin >> a >> b;
//	int* pi = new int[10000];
//	try{
//		Devide(a, b);
//	}
//	catch (char& str){
//		cout << str << endl;
//	}
//	catch (int a){
//		cout << a << endl;
//	}
//	
//	catch (...){
//		delete[] pi;
//		cout << "catch(...) : delete[] pi" << endl;
//		//异常重新抛出
//		throw;
//	}
//
//	delete[] pi;
//	cout << "delete[] pi" << endl;
//}
//
//int main()
//{	
//	try{
//		fun();
//	}
//	catch (string& str){
//		cout << str << endl;
//	}
//	catch (int a){
//		cout << a << endl;
//	}
//	return 0;
//}

class Exception{
public:
	virtual void what(){
		cout << "异常" << endl;
	}
};

class DevideError : public Exception{
public:
	virtual void what(){
		cout << "devided by zero" << endl;
	}
};

class MallcoError : public Exception{
public:
	virtual void what(){
		cout << "malloc failure" << endl;
	}
};

int Devide(int a, int b){
	if (b == 0){
		throw DevideError();
	}
	return a / b;
}

void MallocTest(){
	int* pi =(int*) malloc(0x7fffffff);
	if (pi == nullptr){
		throw MallcoError();
	}
	free(pi);
}

//int main(){
//
//	int a, b;
//	cin >> a >> b;
//	try{
//		Devide(a, b);
//		MallocTest();
//	}
//	catch (Exception& e){
//		e.what();
//	}
//	catch (...){
//		cout << "未知异常" << endl;
//	}
//	return 0;
//
//}

//int main()
//{
//	try
//	{
//		vector<int> vec;
//		vec.at(10) = 10;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//	return 0;
//}
