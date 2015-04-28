/*************************************************************
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
**************************************************************/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> > &mp) {
			int m = mp.size(), n = mp[0].size();
    	int dp[105][105];
    	memset(dp, 0, sizeof(dp));
    	dp[0][1] = 1;
    	for (int i = 1; i <= m; ++i) {
    		for (int j = 1; j <= n; ++j) {
					if (mp[i - 1][j - 1]) {
						dp[i][j] = 0;
						continue;
					}
    			dp[i][j] = dp[i-1][j] + dp[i][j-1];
    		}
    	}
    	return dp[m][n];
    }
};
int main() {
	Solution solution;
	int m, n;
	int mp[][3] = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	vector< vector<int> > vec;
	for (int i = 0; i < 3; ++i) {
		vector<int> tmp;
		for (int j = 0; j < 3; ++j) {
			tmp.push_back(mp[i][j]);
		}
		vec.push_back(tmp);
	}
	while (cin >> m >> n) {
		cout << solution.uniquePathsWithObstacles(vec) << endl;
	}
	return 0;
}
