	#define  _CRT_SECURE_NO_WARNINGS
	#include<iostream> 
	#include<algorithm> 
	using namespace std; //判断素数 
	bool isPrime(int num) { 
		int tmp = sqrt(num);
		//只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除 
		for (int i = 2; i <= tmp; i++) { 
			if (num %i == 0)
				return false; 
		}
		return true; 
	}
	int main() { 
	int num; 
	int half;
	int i;
	while (cin >> num)
	{ half = num / 2; //从中间向两边找 
	for (i = half; i > 0; i--)
	{
		if (isPrime(i) && isPrime(num - i)) 
	break;
	}
	cout << i << endl << num - i << endl; 
	}
	return 0; 
	}