#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		int left = 0;
		int right = n - 1;
		int mid = 0;
		while (left <= right){
			mid = left + (right - left) / 2;
			if (A[mid] == x)
				return mid;
			if (A[mid] > A[left])//左边单调
			{
				if (x >= A[left] && x < A[mid]){
					right = mid - 1;
				}
				else{
					left = mid + 1;
				}

			}
			else if (A[mid] < A[right])//右边单调
			{
				if (x > A[mid] && x <= A[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return 0;
	}
};
int main(){
	vector<int> a = { 6, 7, 8, 1, 2, 3, 4, 5 };
	Finder f;
	cout << f.findElement(a, a.size(), 6) << endl;
	return 0;
}