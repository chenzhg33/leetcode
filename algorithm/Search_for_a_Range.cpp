/*********************************************
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0, r = n - 1, m;
        while (l < r) {

					m = (l + r) >> 1;
					if (target > A[m]) {
						l = m + 1;
					} else {
						r = m;
					}
				}
				vector<int> result(2, -1);
				if (A[l] == target) {
					result[0] = l;
				} else {
					return result;
				}
				l = 0;
				r = n - 1;
				while (l < r) {
					m = (l + r + 1) >> 1;
					if (target < A[m]) {
						r = m - 1;
					} else {
						l = m;
					}
				}
				if (A[l] == target) {
					result[1] = l;
				}
				return result;
    }
};
int main() {
	int a[] = {5, 7, 7, 8, 8, 10};
	int target;
	Solution solution;
	while (cin >> target) {
		vector<int> result = solution.searchRange(a, sizeof(a) / 4, target);
		cout << '[' << result[0] << ',' << result[1] << ']' << endl;
	}
	return 0;
}
