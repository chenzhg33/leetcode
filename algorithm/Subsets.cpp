/**********************************************************
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
**********************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
			result.clear();
			sort(S.begin(), S.end());
			result.push_back(vector<int>());
			int len = S.size();
			for (int i = 1; i <= len; ++i) {
				combination(S, len, 0, a, i, 0);
			}
			return result;
    }
		void combination(vector<int> &vec, int len, int start, int a[], int sublen, int cur) {
			if (sublen == cur) {
				vector<int> tmp(a, a + sublen);
				result.push_back(tmp);
				return;
			}
			for (int i = start; i < len - sublen + 1 + cur; ++i) {
				a[cur] = vec[i];
				combination(vec, len, i + 1, a, sublen, cur + 1);
			}
		}
private:
			vector< vector<int> > result;
			int a[100];
};
int main() {
	Solution solution;
	int a[] = {1, 2, 3, 4};
	vector<int> vec(a, a + 4);
	solution.subsets(vec);
	return 0;
}
