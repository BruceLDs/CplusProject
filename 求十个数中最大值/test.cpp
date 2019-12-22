#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int Num_max(vector<int> a){
	int ret = a[0];
	for (auto& e : a){
		if (e > ret)
			ret = e;
	}
	return ret;
}
int main(){
	vector<int> a = { 1, 4, 5, 8, 9, 2, 6, 7 };
	cout << Num_max(a) << endl;
	return 0;
}