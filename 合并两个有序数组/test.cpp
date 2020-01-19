#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (n == 0)
		return;
	if (m == 0){
		nums1 = nums2;
		return;
	}
	vector<int> nums;
	nums.resize(m + n);
	int i = m + n - 1;
	n--;
	m--;
	while (i >= 0){
		if (m >= 0 && n >= 0){
		if (nums1[m] > nums2[n]){
				nums[i] = nums1[m];
				m--;
			}
			else{
				nums[i] = nums2[n];
				n--;
			}
		}
		else{
			if (n < 0){
				nums[i] = nums1[m];
				m--;
			}
			else if(m < 0){
				nums[i] = nums2[n];
				n--;
			}
		}
		i--;
	}
	nums1 = nums;
}

int main(){
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };
	cout << "原数组：" << endl;
	for (int i = 0; i < 3; i++)
		cout << nums1[i]<< "  ";
	cout << endl;
	merge(nums1, 3, nums2, 3);
	cout << "合并后：" << endl;
	for (auto& e : nums1)
		cout << e << "  ";
	cout << endl;
	return 0;
}