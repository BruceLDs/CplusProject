#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
状态：
  子状态：跳上1级，2级，3级，...，n级台阶的跳法数
  f(n)：还剩n个台阶的跳法数
   状态递推：
   n级台阶，第一步有n种跳法：跳1级、跳2级、到跳n级
   跳1级，剩下n-1级，则剩下跳法是f(n-1)
   跳2级，剩下n-2级，则剩下跳法是f(n-2)
   f(n) = f(n-1)+f(n-2)+...+f(n-n)
   f(n) = f(n-1)+f(n-2)+...+f(0)
   f(n-1) = f(n-2)+...+f(0)
   f(n) = 2*f(n-1)
    初始值：
	f(1) = 1
	f(2) = 2*f(1) = 2
	f(3) = 2*f(2) = 4
	f(4) = 2*f(3) = 8
	所以它是一个等比数列
	f(n) = 2^(n-1)
	 返回结果：f(N)
*/
class Solution {
public:
	int jumpFloorII(int number) {
		if (number <= 0)
			return 0;
		int *a = new int[number + 1];
		a[1] = 1;
		for (int i = 2; i <= number; i++)
			a[i] = 2 * a[i - 1];
		return a[number];
	}
};
/*每个台阶看成一个位置，除过最后一个位置，其它位置都有两种可能性，
所以总的排列数为2 ^ (n - 1) * 1 = 2 ^ (n - 1)*/
class Solution2 {
public:
	int jumpFloorII(int number) {
		if (number <= 0)
			return 0;
		int total = 1;
		for (int i = 1; i < number; i++)
			total *= 2;
		return total;
	}
};
/*
扩展：降低时间复杂度
  上述实现的时间复杂度:O(N)
    O(1)的实现：使用移位操作
	*/
class Solution3 {
public:
	int jumpFloorII(int number) {
		if (number <= 0)
			return 0;
		return 1 << (number - 1);
	}
};
void test(){
	Solution s1;
	Solution2 s2;
	Solution3 s3;
	cout << s1.jumpFloorII(10) << endl;
	cout << s2.jumpFloorII(10) << endl;
	cout << s3.jumpFloorII(10) << endl;
	system("pause");
}
int main(){
	test();
	return 0;
}