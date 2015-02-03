/******************************************************
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

******************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
	public:
		int trap(int A[], int n) {
			if (n == 1) return 0;
			int l = 0, r = n - 1;
			int ml = l, mr = r;
			int sum = min(A[l], A[r]) * (r - l - 1);
			while (l < r - 1) {
				cout << sum << ' ';
				if (A[l] < A[r]) {
					++l;
					if (A[l] > A[ml]) {
						sum += ((min(A[l], A[mr]) - A[ml]) * (mr - l - 1) - A[ml]);
						ml = l;
					} else {
						sum -= A[l];
					}
				} else {
					--r;
					if (A[r] > A[mr]) {
						sum += ((min(A[ml], A[r]) - A[mr]) * (r - ml - 1) - A[mr]);
						mr = r;
					} else {
						sum -= A[r];
					}
				}
			}
			return sum;
		}
};
int main() {
	int A[] = {5, 2, 1, 2, 1, 5};//{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	Solution solution;
	cout << solution.trap(A, sizeof(A) / 4);
	return 0;
}
