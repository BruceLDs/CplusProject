#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void Arrayswap(vector<T> a, vector<T> b){
	vector<T>::iterator ita = a.begin(), itb = b.begin();
	while ( ita != a.end() || itb != b.end()){
		int temp = *ita;
		*ita = *itb;
		*itb = temp;
		ita++;
		itb++;
	}
}
int main(){
	vector<int> a = { 1, 3, 5 };
	vector<int> b = { 2, 4, 6 };
	Arrayswap(a, b);
	for (auto& e : a)
		cout << e << "    ";
	cout << endl;
	for (auto& e : b)
		cout << e << "    ";
	cout << endl;

	return 0;
}