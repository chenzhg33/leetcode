/********************************************************************
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
********************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
			if (n == 0) return 0;
			int p = 1;
			bool dup = false;
			for (int i = 1; i < n; ++i) {
				if (A[i] == A[i-1]) {
					if (!dup) {
						A[p++] = A[i];
					}
					dup = true;
				} else {
					A[p++] = A[i];
					dup = false;
				}
			}
			for (int i = 0; i < p; ++i) {
				cout << A[i] << ' ';
			}
			return p;
    }
};
int main() {
	int a[] = {1, 2, 3};
	Solution solution;
	solution.removeDuplicates(a, sizeof(a) / 4);
	return 0;
}
