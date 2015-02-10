/****************************************************
Find the contiguous subarray within an array (containing at least one number) 
which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*****************************************************/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(int A[], int n) {     
			if (n == 1) return A[0];
			int ndp[n + 1], dp[n + 1], mx = -10000000;
			memset(ndp, 0, sizeof(ndp));
			memset(dp, 0, sizeof(dp));
			for (int i = 0; i < n; ++i) {
				if (A[i] > 0) {
					if (dp[i] == 0) {
						dp[i+1] = A[i];
					} else {
						dp[i+1] = dp[i] * A[i];
					}
					if (ndp[i] < 0) {
						ndp[i+1] = ndp[i] * A[i];
					}
				} else if (A[i] < 0) {
					if (dp[i] > 0) {
						ndp[i+1] = dp[i] * A[i];
					} else {
						ndp[i+1] = A[i];
					}
					if (ndp[i] < 0) {
						dp[i+1] = ndp[i] * A[i];
					}
				}
				cout << dp[i+1] << ' ' << ndp[i+1] << endl;
				mx = max(mx, dp[i+1]);
			}
			return mx;
    }
};
int main() {
	Solution solution;
	int a[] = {-2, 3, -4};
	cout << solution.maxProduct(a, sizeof(a)/4);
	return 0;
}
