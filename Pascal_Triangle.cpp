/*********************************************************
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*********************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
			vector< vector<int> > re;
			if (numRows == 0) return re;
			re.push_back(vector<int>(1, 1));
			for (int i = 1; i < numRows; ++i) {
				vector<int> tmp;
				for (int j = 0; j <= i; ++j) {
					if (j == 0) {
						tmp.push_back(1);
					} else if (j == i) {
						tmp.push_back(1);
					} else {
						tmp.push_back(re[i-1][j] + re[i-1][j-1]);
					}
				}
				re.push_back(tmp);
			}
			return re;
    }
};
int main() {
	Solution solution;
	int numRows;
	while (cin >> numRows) {
		solution.generate(numRows);
	}
	return 0;
}
