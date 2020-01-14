#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left < right){
		if (nums[left] == target)
			return left;
		if (nums[right] == target)
			return right;
		if (nums[left] > target)
			return left;
		if (nums[right] < target)
			return right + 1;
		left++;
		right--;
	}
	if (nums[left] >= target)
		return left;
	return left + 1;
}
int main(){
	vector<int> arr = { 1, 2, 3, 4, 5 };
	int ret = searchInsert(arr, 3);
	cout << ret << endl;
	return 0;
}
