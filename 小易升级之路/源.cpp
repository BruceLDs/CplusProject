#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int fun(int m, int n){
	int rem;			//������������Ϊ0��ʱ������m��Ϊ���Լ��
	//���ý�С�����Խϴ����ȡ�࣬���������Խ�С�������ֱ࣬������Ϊ�� 
	while (n > 0){
		rem = m % n;
		m = n;
		n = rem;
	}
	return m;			//���������			
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