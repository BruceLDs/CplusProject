#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<math.h>
using namespace std;
bool is_prime(int n){
	int i;
	int k = (int)sqrt((double)n);
	for ( i = 2; i <= k; i++)
	if (n%i == 0)
		break;
	// ����������ѭ������ômΪ����
	// ע�����һ��ѭ������ִ��i++����ʱ i=k+1��������i>k 
	if (i > k)
		return true;
	return false;
}
int main(){
	int key = 0;
	while (cin >> key){
	int left = key / 2;
	int right = left;
	while (left > 0)
	{
		if (is_prime(left) && is_prime(right))
			break;
		left--;
		right++;
	}
	cout << left << " " << right << endl;
	}
	return 0;
}