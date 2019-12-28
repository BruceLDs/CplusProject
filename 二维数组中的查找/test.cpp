#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

bool Find(int target, vector<vector<int> > array) {
	if (array.size() == 0)
		return false;
	int x = 0;
	int y = array[0].size() - 1;
	while (y >= 0 && x < array.size()){
		if (array[x][y] > target)
			y--;
		else if (array[x][y] < target)
			x++;
		else
			return true;
	}
	return false;
}
int main(){
	vector<vector<int>> a =
	{ { 1, 2, 3 },
	{4, 5, 6},
	{7, 8, 9}
	};
	int i;
	while (cin >> i){
		bool ret = Find(i, a);
		cout << ret << endl;
	}
	return 0;
}