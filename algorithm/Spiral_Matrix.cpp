#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector< vector<int> > &matrix) {
	  if (matrix.size() == 0) return vector<int>();
		int rows = matrix.size(), cols = matrix[0].size();
		int startx = 0, starty = 0;
		int endx = rows - 1, endy = cols - 1;
		vector<int> result; 
		while (true) {
			for (int i = starty; i <= endy; ++i) result.push_back(matrix[startx][i]);
			for (int i = startx + 1; i < endx; ++i) result.push_back(matrix[i][endy]);
			if (startx != endx) {
				for (int i = endy; i >= starty; --i) result.push_back(matrix[endx][i]);
			}
			if (starty != endy) {
				for (int i = endx - 1; i > startx; --i) result.push_back(matrix[i][startx]);
			}
			startx++;
			endx--;
			starty++;
			endy--;
			if (startx > endx || starty > endy) break;
		}		
		return result;		
	}
};
int main() {
	//int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	//int a[][1] = {{1}, {2}, {3}};
	int a[][1] = {{1}};
	vector< vector<int> > vec;
	for (int i = 0; i < 1; ++i) {
		vector<int> tmp;
		for (int j = 0; j < 1; ++j) {
			tmp.push_back(a[i][j]);
		}
		vec.push_back(tmp);
	}
	Solution solution;
	solution.spiralOrder(vec);
	system("pause");
	return 0;
}
