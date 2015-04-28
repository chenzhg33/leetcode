/******************************************************************
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*******************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool canJump(int A[], int n) {      
			if (n == 1) return true;
			int cur = 0;
			while (A[cur] > 0) {
				if (cur + A[cur] > n - 2) {
					return true;
				}
				int best = 1;
				int mx = -100;
				for (int i = 1; i <= A[cur]; ++i) {
					if (mx < i + A[cur + i]) {
						mx = i + A[cur + i];
						best = i;
					}
				}
				cur += best;
			}
			return false;
    }
};
int main() {
	Solution solution;
	int a[] = {2, 3, 1, 3, 1, 0, 0};
	//int a[] = {3, 2, 1, 0, 4};
	cout << solution.canJump(a, sizeof(a) / 4);
	return 0;
}
