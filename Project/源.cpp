#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//int main(){
//	int x, y;
//	for (x = 0, y = 0; (y = 123) && (x<4); x++)
//		cout << x << "    次"<< endl;
//
//	return 0;
//}
int main(void) { 
	printf("%s , %5.3s\n", "computer", "computer");  
	int y = 1009;
	int* p = &y;
	*p++;//表示指针加加
	cout << *p << endl;
	int a = 10;
	double b = 3.14;
	cout << 'A' + a + b << endl;
	return 0; 
}