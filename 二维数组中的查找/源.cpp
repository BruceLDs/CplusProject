#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int x = 0;
		int y = array[0].size() - 1;
		while (y >= 0 && x < array.size()){
			if (array[x][y] > target)
				y--;
			if (array[x][y] > target)
				x++;
			if (array[x][y] == target)
				return true;
		}
		return false;
	}
};

int main(){
	Solution s;
	vector<vector<int>> arr;
	arr = { { 1, 2, 3}, { 2, 3, 4 }, {3, 4, 5} };
	cout << s.Find(4, { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } }) << endl;
	return 0;
}

