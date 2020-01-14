#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
	int slow = 0;
	int fast = 0;
	while (fast < nums.size()){
		if (nums[fast] == val)
			fast++;
		else{
			nums[slow] = nums[fast];
			fast++;
			slow++;
		}
	}
	return slow;
}

int main(){
	vector<int> arr = { 3, 2, 2, 3 };
	int ret = removeElement(arr, 3);
	for (int i = 0; i < ret; i++){
        cout << arr[i] << "   ";
	}
	cout << endl;
	return 0;
}