#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int fun(int m, int n){
	int rem;			//余数，当余数为0的时候，最后的m即为最大公约数
	//先用较小的数对较大的数取余，再用余数对较小的数求余，直到余数为零 
	while (n > 0){
		rem = m % n;
		m = n;
		n = rem;
	}
	return m;			//将结果返回			
}
int Endpower(vector<int> arr, int n, int a){
	for (auto& e : arr){
		if (a >= e)
			a += e;
		else
			a += fun(e, a);
	}

	return a;
}
int main(){
	int n, a;
	vector<int> arr;
	while (cin >> n >> a){
		arr.resize(n);
		for (auto& e : arr)
			cin >> e;
		cout << Endpower(arr, n, a) << endl;
	}
	return 0;
}