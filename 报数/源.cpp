#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		std::string s = "1";
		for (int i = 1; i < n; i++) //��N����
		{
			std::string tmp;
			for (int j = 0; j < s.size(); j++)//����s
			{
				int count = 1;
				while (j + 1 < s.size() && s[j + 1] == s[j]) { //ͳ���ظ�
					count++;
					j++;
				}
				tmp += std::to_string(count) + s[j];
			}
			s = tmp; //�����ַ���
		}
		return s;
	}
};

int  main(){
	Solution s;
	s.countAndSay(7);
	return 0;
}