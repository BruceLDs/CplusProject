#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
using namespace std;


//题解未通过，当存在负数时，无法通过题解
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

//力扣正确题解
int pivotIndex1(vector<int>& nums) {
	if (nums.size() == 0)
		return -1;
	int leftsum = 0;
	int sum = 0;
	for (auto& e : nums)
		sum += e;
	if (sum - nums[0] == 0)
		return 0;
	int i = 0;
	while (i < nums.size()){
		leftsum += nums[i];
		i++;
		if (i < nums.size() && sum - leftsum - nums[i] == leftsum)
			return i;
	}
	return -1;
}

void test(vector<int> nums){
int ret = pivotIndex(nums);
	cout << ret << endl;
}
void test1(vector<int> nums1){
	int ret = pivotIndex1(nums1);
	cout << ret << endl;
}
int main(){
	vector<int> nums = { 1, 7, 3, 6, 5, 6 };
	//test(nums);
	vector<int> nums1 = { -1, -1, -1, -1, -1, -1};
	test(nums);
	test1(nums1);
	return 0;
}