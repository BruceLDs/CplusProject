#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#define max 5
using namespace std;
//数学解法，不适用
void PrintPrismatic(){
	for (int i = 0; i <= max; i++){
		for (int j = 0; j < 2 * max - 2 * i; j++)
			cout << " ";
		for (int j = 0; j < 4 * i + 1; j++)
			cout << "*";
		cout << endl;
	}
	for (int i = max - 1; i >= 0; i--){
		for (int j = 2 * max - 2 * i - 1; j >= 0; j--)
			cout << " ";
		for (int j = 4 * i ; j >= 0; j--)
			cout << "*";
		cout << endl;
	}
}
//程序员解法
void PrintPrismatic1(){
	vector<string> s;
	int zone = 4 * max + 1;
	s.resize(zone, " ");
	int left, right, mid = zone / 2;
	left = mid;
	right = mid;
	for (int i = 0; i < max; i++){
		s[left] = "*";
		s[right] = "*";
		left--;
		right++;
		for (auto& e : s)
			cout << e;
		    cout << endl;
	}
	while(left < right){
		s[left] = " ";
		s[right] = " ";
		left++;
		right--;
		for (auto& e : s)
			cout << e;
		cout << endl;
	}
}
int main(){
	PrintPrismatic();
	PrintPrismatic1();
	return 0;
}