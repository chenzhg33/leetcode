/****************************************************************************************
Given a triangle, find the minimum path sum from top to bottom.
 Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
******************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
       for (int i = 1; i < triangle.size(); ++i) {
				 for (int j = 0; j < triangle[i].size(); ++j) {
					 if (j == 0) {
						 triangle[i][j] += triangle[i-1][j];
					 } else if (j == i) {
						 triangle[i][j] += triangle[i-1][j-1];
					 } else {
						 triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
					 }
					 //cout << triangle[i][j] << ' ';
				 }
			 }
			 return *min_element((--triangle.end())->begin(), (--triangle.end())->end());
		}
};
int main() {
	Solution solution;
	int a[][4] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	vector< vector<int> > tri;
	for (int i = 0; i < 4; ++i) {
		vector<int> tmp;
		for (int j = 0; j < 4; ++j) {
			tmp.push_back(a[i][j]);
		}
		tri.push_back(tmp);
	}
	cout << solution.minimumTotal(tri) << endl;
	return 0;
}
