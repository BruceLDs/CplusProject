#define  _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int fun(int m, int n){
//	int rem;			//余数，当余数为0的时候，最后的m即为最大公约数
//	//先用较小的数对较大的数取余，再用余数对较小的数求余，直到余数为零 
//	while (n > 0){
//		rem = m % n;
//		m = n;
//		n = rem;
//	}
//	return m;			//将结果返回			
//}
//int Endpower(vector<int> arr, int n, int a){
//	for (auto& e : arr){
//		if (a >= e)
//			a += e;
//		else
//			a += fun(e, a);
//	}
//
//	return a;
//}
//int main(){
//	int n, a;
//	vector<int> arr;
//	while (cin >> n >> a){
//		arr.resize(n);
//		for (auto& e : arr)
//			cin >> e;
//		cout << Endpower(arr, n, a) << endl;
//	}
//	return 0;
//}


#include<vector>
#include<iostream>
using namespace std;
int GCD(int a, int b)
{
	int c;
	while (c = a % b)
	{
		a = b;
		b = c;
	}
	return b;
}
int main()
{
	int n, power;
	vector<int> num;
	while (cin >> n >> power)
	{
		num.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}
		for (int k = 0; k < n; k++)
		{
			if (num[k] < power)
			{
				power += num[k];
			}
			else
			{
				power += GCD(power, num[k]);
			}
		}
		cout << power << endl;
	}
	return 0;
}