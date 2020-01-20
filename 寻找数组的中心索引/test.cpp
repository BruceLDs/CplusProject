#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
	if (nums.size() == 0)
		return -1;
	if (nums.size() == 1)
		return 0;
	int ret = 0;
	int left = 0;
	int right = nums.size() - 1;
	int nleft = nums[left];
	int nright = nums[right];
	while (left < right){
		if (nleft > nright){
			right--;
			if (left < right)
				nright += nums[right];
		}
		else if (nleft < nright){
			left++;
			if (left < right)
				nleft += nums[left];
		}
		else if (nleft == nright){
			right--;
			left++;
			if (left < right){
				nleft += nums[left];
				nright += nums[right];
			}
		}
	}
	if (nleft == nright && left == right)
		return left;
	else
		return -1;
}

int main(){
	vector<int> nums = { 1, 7, 3, 6, 5, 6 };
	int ret = pivotIndex(nums);
	cout << ret << endl;
	return 0;
}