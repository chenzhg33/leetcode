/*********************************************************
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. 
If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n - 1, m;
        while (l < r) {
					m = (l + r) >> 1;
					if (A[l] < A[r]) {
						if (target <= A[m]) {
							r = m;
						} else {
							l = m + 1;
						}
					} else {
						if (A[m] >= A[l]) {
							if (target <= A[m] && target >= A[l]) {
								r = m;
							} else {
								l = m + 1;
							}
						} else if (A[m] <= A[r]) {
							if (target > A[m] && target <= A[r]) {
								l = m + 1;
							} else {
								r = m;
							}
						}
					}
				}
				if (A[l] == target) {
					return l;
				}
				return -1;
    }
};
int main() {
	Solution solution;
	int a[] = {4, 5, 6, 7, 0, 1, 2};
	int target;
	while (cin >> target) {
		cout << solution.search(a, sizeof(a) / 4, target) << endl;
	}
	return 0;
}
