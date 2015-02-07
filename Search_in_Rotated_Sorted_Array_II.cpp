/*********************************************************
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n - 1, m;
        if (A[l] == target) return true;
        ++l;
        while (l < n && A[l] == A[l-1]) ++l;
        if (l == n) return false;
        if (A[r] == target) return true;
        --r;
        while (r > -1 && A[r] == A[r+1]) --r;
        if (r == -1) return false;
        while (l < r) {
					m = (l + r) >> 1;
					if (target <= A[m]) {
						r = m;
					} else {
						l = m + 1;
					}
				}
				if (A[l] == target) {
					return true;
				}
				return false;
    }
};
int main() {
	Solution solution;
	int a[] = {1, 1, 1, 1};
	int target;
	while (cin >> target) {
		cout << solution.search(a, sizeof(a) / 4, target) << endl;
	}
	return 0;
}
