/**************************************************************
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
**************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
			int rows = grid.size(), cols = grid[0].size();
			for (int i = 1; i < cols; ++i) {
				grid[0][i] += grid[0][i-1];
			}
			for (int i = 1; i < rows; ++i) {
				grid[i][0] += grid[i-1][0];
			}
			for (int i = 1; i < rows; ++i) {
				for (int j = 1; j < cols; ++j) {
					grid[i][j] = min(grid[i-1][j] + grid[i][j], grid[i][j-1] + grid[i][j]);
				}
			}
			return grid[rows - 1][cols - 1];
    }
};
int main() {
	int a[][4] = {{1, 2, 3, 4},
								{1, 1, 2, 4},
								{2, 1, 3, 5},
								{5, 1, 1, 1}};
	vector< vector<int> > vec;
	for (int i = 0; i < 4; ++i) {
		vector<int> tmp;
		for (int j = 0; j < 4; ++j) {
			tmp.push_back(a[i][j]);
		}
		vec.push_back(tmp);
	}
	Solution solution;
	cout << solution.minPathSum(vec);
	return 0;
}
