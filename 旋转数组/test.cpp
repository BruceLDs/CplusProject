#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void rmove(vector<int>& nums){
	int temp = nums[nums.size() - 1];
	int fast = nums.size() - 2;
	int slow = nums.size() -1;
	while (fast >= 0){
		nums[slow] = nums[fast];
		fast--;
		slow--;
	}
	nums[0] = temp;
}

void rotate(vector<int>& nums, int k) {
	int i = 0;
	while (i < k){
		rmove(nums);
		i++;
	}
}

int main(){
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	for (auto& e : nums)
		cout << e << "    ";
	cout << endl;
	//rmove(nums);
	rotate(nums, 3);
	for (auto& e : nums)
		cout << e << "    ";
	cout << endl;
	return 0;
}