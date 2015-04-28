/**********************************************
Given a sorted array and a target value, 
return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
***********************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
			int l = 0, r = n - 1, m;
			while (l < r) {
				m = (l + r) >> 1;
				if (target <= A[m]) {
					r = m;
				} else {
					l = m + 1;
				}
			}
			if (A[l] >= target) {
				return l;
			}
			return l + 1;
    }
};
int main() {
	Solution solution;
	int a[] = {1,3,5,6};
	int target;
	while (cin >> target) {
		cout << solution.searchInsert(a, sizeof(a) / 4, target) << endl;
	}
	system("pause");
	return 0;
}
