/********************************************
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
**********************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
			int rows = matrix.size();
			if (rows == 0) return false;
			int cols = matrix[0].size();
			int l = 0, r = rows * cols - 1, m;
			while (l < r) {
				m = (l + r) >> 1;
				if (target > matrix[m / cols][m % cols]) {
					l = m + 1;
				} else {
					r = m;
				}
			}
			return matrix[l / cols][l % cols] == target;
    }
};
int main() {
	Solution solution;
	int a[][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
	vector< vector<int> > vec;
	for (int i = 0; i < 3; ++i) {
		vector<int> tmp;
		for (int j = 0; j < sizeof(a[0]) / 4; ++j) {
			tmp.push_back(a[i][j]);
		}
		vec.push_back(tmp);
	}
	int target;
	while (cin >> target) {
		cout << solution.searchMatrix(vec, target) << endl;
	}
	return 0;
}
