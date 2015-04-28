/*********************************************************
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*********************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(int A[], int n) {      
			int p = 0;
			while (p < n) {
				cout << "p: " << p << ' ';
				for (int i = 0; i < n; ++i) {
					cout << A[i] << ' ';
				}
				cout << endl;
				if (A[p] > 0 && A[p] <= n && A[p] != p + 1 && A[p] != A[A[p]-1]) {
					swap(A[p], A[A[p]-1]);
				} else {
					++p;
				}
			}
			for (int i = 1; i <= n; ++i) {
				if (A[i-1] != i) {
					return i;
				}
			}
			return n + 1;
		}
};
int main() {
	Solution solution;
	int a[] = {1, 2, 0};
	cout << solution.firstMissingPositive(a, sizeof(a) / 4);
	return 0;
}
