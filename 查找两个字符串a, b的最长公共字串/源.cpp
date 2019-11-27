/*#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
string restring(string s1, string s2){
	string ret;
	int i = 0;
	for (i = 0; i < (s1.size() < s2.size() ? s1.size() : s2.size()); i++){
		string temp;
		int start = i;
		while (s1[i] == s2[i] && i < (s1.size() < s2.size() ? s1.size() : s2.size())){
			temp += s1[i];
			i++;
		}
		i = start;
		if (temp.size() > ret.size())
			ret = temp;
	}
	return ret;
}
int main(){
	string s1, s2;
	while (cin >> s1 && cin >> s2){
		string ret = restring(s1, s2);
		cout << ret << endl;
	}

	return 0;
}*/

#include<iostream>
#include<string>
using namespace std;
string restring(string s1, string s2){
	string ret;
	int i = 0;
	int j = 0;
	if (s1.size() < s2.size())
		swap(s1, s2);
	for (i = 0; i < s2.size(); i++){
		string temp;
		int start = i;
		if (j == s1.size())
			j = 0;
		while (s1[j] != s2[i])
			j++;
		while (s1[j] == s2[i] && j < s1.size()){
			temp += s1[i];
			i++;
			j++;
		}
		i = start;
		if (temp.size() > ret.size())
			ret = temp;
	}
	return ret;
}
int main(){
	string s1, s2;
	while (cin >> s1 && cin >> s2){
		string ret = restring(s1, s2);
		cout << ret << endl;
	}
}