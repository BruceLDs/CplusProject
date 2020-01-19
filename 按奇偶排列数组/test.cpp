#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
vector<int> sortArrayByParity(vector<int>& A) {
	int left = 0;
	int right = A.size() - 1;
	while (left < right){
		if (A[right] % 2 != 0)
			right--;
		else if (A[left] % 2 == 0)
			left++;
		else{
			swap(A[left], A[right]);
		}
	}
	return A;
}

int main(){
	vector<int> A = { 1, 2, 3, 4 };
	vector<int> ret = sortArrayByParity(A);
	for (auto& e : ret)
		cout << e << "  ";
	cout << endl;
	return 0;
}