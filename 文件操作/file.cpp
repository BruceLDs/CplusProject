#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
void test(){
	ifstream file("test.txt", ios::binary);
	char p[100];
	file.read(p, 10);
	for (auto& e : p)
		cout << e;
	cout << endl;
	//cout << file.gcount();
	ifstream f0("test.txt", ios::out);
	char* ch = "0x123456";
	cout.write( ch, 5);

}

int main(){
	test();
	return 0;
}