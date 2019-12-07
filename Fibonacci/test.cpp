#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Solution{
public:
	int Fibonacci(int n){
		// ��ʼֵ
		if (n <= 0){
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		// F(n)=F(n-1)+F(n-2)
		return Fibonacci(n - 2) + Fibonacci(n - 1);
	}
};
/*
�ݹ�ķ���ʱ�临�Ӷ�ΪO(2^n)������n���������ָ��������Ч�ʵ���
������Ƚϴ�ʱ�����ܵ���ջ���
�ڵݹ�������д������ظ�����
*/
/*
����������̬�滮
״̬��F(n)
״̬���ƣ�F(n)=F(n-1)+F(n-2)
��ʼֵ��F(1)=F(2)=1
���ؽ����F(N)
*/
class Solution2{
public:
	int Fibonacci(int n){
		// ��ʼֵ
		if (n <= 0){
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		// ����һ�����飬����������Ľ⣬��ĿҪ��ӵ�0�ʼ
		int* record = new int[n + 1];
		record[0] = 0;
		record[1] = 1;
		for (int i = 2; i <= n; i++){
			// F(n)=F(n-1)+F(n-2)
			record[i] = record[i - 1] + record[i - 2];
		}
		return record[n];
		delete[] record;
	}
};
/*
�����ⷨ�Ŀռ临�Ӷ�ΪO(n)
��ʵF(n)ֻ�������ڵ�ǰ�����йأ�����û�б�Ҫ��������������Ľ�
ֻ��Ҫ��������������Ľ�Ϳ���
���淽���Ŀռ临�ӶȽ�ΪO(1)
*/
class Solution3{
public:
	int Fibonacci(int n){
		// ��ʼֵ
		if (n <= 0){
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		int fn1 = 1;
		int fn2 = 1;
		int result = 0;
		for (int i = 3; i <= n; i++){
			// F(n)=F(n-1)+F(n-2)
			result = fn2 + fn1;
			// ����ֵ
			fn1 = fn2;
			fn2 = result;
		}
		return result;
	}
};
void test(){
	Solution s1;
	Solution2 s2;
	Solution3 s3;
	cout << s1.Fibonacci(10) << endl;
	cout << s2.Fibonacci(10) << endl;
	cout << s3.Fibonacci(10) << endl;
	system("pause");
}
int main(){
	test();
	return 0;
}