#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	// 注意这里多给了一个值，是处理越界的情况的比较
	vector<int> a; a.resize(n + 1);
	a[n] = 0;
	//读入数组
	int i = 0;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	i = 0;
	int count = 0;
	while (i < n)
	{
		// 非递减子序列
		if (a[i] < a[i + 1])
		{
			while (i < n && a[i] <= a[i + 1])
				i++;
			count++; i++;
		}
		else if (a[i] == a[i + 1])
		{
			i++;
		}
		else // 非递增子序列
		{
			while (i < n && a[i] >= a[i + 1])
				i++;
			count++; i++;
		}
	}
	cout << count << endl;
	return 0;
}