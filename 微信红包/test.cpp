#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		//超过一半的数排序之后必然排在中间
		int middle = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			//统计排在中间的数的个数
			if (gifts[i] == middle)
			{
				count++;
			}
		}
		//如果个数大于一半，则存在超过一半的数
		if (count > n / 2)
			return middle;
		else
			return 0;
	}
};
/*思路二：map统计*/
class Gift1 {
public:
	int getValue(vector<int> gifts, int n) {
		map<int, int> count;
        int middle = gifts.size() / 2;
		for (const auto& e : gifts)
		{
			++count[e];
		}
		for (const auto& e : count)
		{
			if (e.second >= middle)
				return e.first;
		}
		return 0;
	}
};
void test(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(2);
	Gift g;
	Gift1 g1;
	cout << g.getValue(a, 5) << endl;
	cout << g1.getValue(a, 5) <<endl;
}
int main(){
	test();
	system("pause");
	return 0;
}