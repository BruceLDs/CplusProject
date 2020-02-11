#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;
int repeatedNTimes(vector<int>& A) {
	int N = A.size() / 2;
	unordered_map<int, int> m;
	for (auto& e : A){
		m[e]++;
		cout << e << endl;
	}
	cout << endl;
	for (auto& e : m)
		cout << e.first << " ---> " << e.second << endl;
	cout << endl;
	int ret;
	for (auto& e : m){
		if (e.second == N){
			ret = e.first;
			break;
		}
	}
	return ret;
}
int main(){
	vector<int> A = { 1, 6, 6, 6, 7, 8 };
	int ret = repeatedNTimes(A);
	cout << ret << endl;
	return 0;
}