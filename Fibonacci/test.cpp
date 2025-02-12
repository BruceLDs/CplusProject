#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Solution{
public:
	int Fibonacci(int n){
		// 初始值
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
递归的方法时间复杂度为O(2^n)，随着n的增大呈现指数增长，效率低下
当输入比较大时，可能导致栈溢出
在递归过程中有大量的重复计算
*/
/*
方法二：动态规划
状态：F(n)
状态递推：F(n)=F(n-1)+F(n-2)
初始值：F(1)=F(2)=1
返回结果：F(N)
*/
class Solution2{
public:
	int Fibonacci(int n){
		// 初始值
		if (n <= 0){
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		// 申请一个数组，保存子问题的解，题目要求从第0项开始
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
上述解法的空间复杂度为O(n)
其实F(n)只与它相邻的前两项有关，所以没有必要保存所有子问题的解
只需要保存两个子问题的解就可以
下面方法的空间复杂度将为O(1)
*/
class Solution3{
public:
	int Fibonacci(int n){
		// 初始值
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
			// 更新值
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