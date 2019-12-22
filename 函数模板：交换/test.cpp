#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
template<class T>
void swap(T* a, T* b){
	T temp = *a;
	*a = *b;
	*b = temp;
}
void test(){
	//int a = 10;
	//int b = 20;
	//swap(&a, &b);
	//cout << a <<" , "<< b << endl;
	string a = "hello";
	string b = "swap";
	swap(&a, &b);
	cout << a << " , " << b << endl;

}
int main(){
	test();

	return 0;
}
