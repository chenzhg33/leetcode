#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		int startx = 0, starty = 0;
		int endx = n - 1, endy = n - 1;
		vector< vector<int> > result; 
		int index = 1;
		int a[n][n];
		while (true) {
			for (int i = starty; i <= endy; ++i) a[startx][i] = index++;
			for (int i = startx + 1; i < endx; ++i) a[i][endy] = index++;
			if (startx != endx) {
				for (int i = endy; i >= starty; --i) a[endx][i] = index++;
			}
			if (starty != endy) {
				for (int i = endx - 1; i > startx; --i) a[i][startx] = index++;
			}
			startx++, endx--, starty++, endy--;
			if (startx > endx || starty > endy) break;
		}
		for (int i = 0; i < n; ++i) {
			vector<int> tmp(a[i], a[i] + n);
			result.push_back(tmp);
		}
		return result;		
	}
};
int main() {
	Solution solution;
	vector< vector<int> > r = solution.generateMatrix(4);
	for (int i = 0; i < r.size(); ++i) {
		for (int j = 0; j < r[i].size(); ++j) {
			cout << r[i][j] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
