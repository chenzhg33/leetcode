/*********************************************************
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*********************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int numRows) {
			++numRows;
			if (numRows < 0) return vector<int>();
			vector<int> re(numRows, 1);
			for (int i = 1; i < numRows; ++i) {
				for (int j = i - 1; j > 0; --j) {
					re[j] += re[j-1];
				}
			}
			return re;
    }
};
int main() {
	Solution solution;
	int numRows;
	while (cin >> numRows) {
		solution.getRow(numRows);
	}
	return 0;
}
