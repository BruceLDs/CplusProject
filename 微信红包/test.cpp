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
		//����һ���������֮���Ȼ�����м�
		int middle = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			//ͳ�������м�����ĸ���
			if (gifts[i] == middle)
			{
				count++;
			}
		}
		//�����������һ�룬����ڳ���һ�����
		if (count > n / 2)
			return middle;
		else
			return 0;
	}
};
/*˼·����mapͳ��*/
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