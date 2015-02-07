/******************************************
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*********************************************/
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
			int start = 0, end = n - 1;
			int i = 0;
			while (i <= end) {
				while(i <= end && A[i] > 1) {
					swap(A[i], A[end]);
					--end;
				}
				if (A[i] < 1) {
					swap(A[i], A[start]);
					++start;
				}
				++i;
			}
			for (int k = 0; k < n; ++k) {
				cout << A[k] << ' ';
			}
    }
};
int main() {
	Solution solution;
	//int a[] = {0, 1, 0, 1, 2, 2, 1, 0, 2, 1};
	int a[] = {2};
	solution.sortColors(a, sizeof(a) / 4);
	system("pause");
	return 0;
}
