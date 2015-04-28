/*********************************************************
iven an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*********************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int jump(int A[], int n) {
   		if (n == 1) return 0;
			int cur = 0, step = 1;
			while (A[cur] > 0) {
				if (cur + A[cur] > n - 2) {
					return step;
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
				++step;
			}
			return -1;
    }
};
int main() {
	Solution solution;
	int a[] = {2, 3, 1, 1, 4};
	cout << solution.jump(a, sizeof(a) / 4);
	return 0;
}
