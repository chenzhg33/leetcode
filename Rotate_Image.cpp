/***********************************************************
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
***********************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
			int n = matrix.size();
			int p[4][2] = {{0, 0}, {0, n - 1}, {n - 1, n - 1}, {n - 1, 0}};
			while (p[0][1] < p[1][1]) {
				for (int i = 0; i < n - 1; ++i) {
					p[0][1] += i, p[1][0] += i, p[2][1] -= i, p[3][0] -= i;
					int tmp = matrix[p[3][0]][p[3][1]];
					for (int j = 3; j > 0; --j) {
						matrix[p[j][0]][p[j][1]] = matrix[p[j-1][0]][p[j-1][1]];
					}
					matrix[p[0][0]][p[0][1]] = tmp;
					p[0][1] -= i, p[1][0] -= i, p[2][1] += i, p[3][0] += i;
				}
				++p[0][0], ++p[0][1];
				--p[2][0], --p[2][1];
				++p[1][0], --p[1][1];
				--p[3][0], ++p[3][1];
				n -= 2;
			}
    }
};
int main() {
	int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	//int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	//int a[][1] = {{1}};
	//int a[][2] = {{1, 2}, {3, 4}};
	vector< vector<int> > vec;
	Solution solution;
	for (int i = 0; i < sizeof(a[0]) / 4; ++i) {
		vector<int> tmp;
		for (int j = 0; j < sizeof(a[0]) / 4; ++j) {
			tmp.push_back(a[i][j]);
		}
		vec.push_back(tmp);
	}
	solution.rotate(vec);
	return 0;
}

