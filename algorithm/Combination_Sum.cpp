/****************************************************
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
****************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &vec, int t) {
			target = t;
			for (auto it = vec.begin(); it != vec.end(); ++it) {
				dfs(vec, *it, 0, *it);
			}
			return result;
    }
		void dfs(vector<int> &vec, int cur, int index, int sum) {
			if (sum > target) return;
			path[index++] = cur;
			if (sum == target) {
				vector<int> tmp;
				for (int i = 0; i < index; ++i) {
					tmp.push_back(path[i]);
				}
				result.push_back(tmp);
				return;
			}
			for (auto it = vec.begin(); it != vec.end(); ++it) {
				if (*it < cur) continue;
				dfs(vec, *it, index, sum + *it);
			}
		}
private:
		vector< vector<int> > result;
		int target;
		int path[1000];
};
int main() {
	Solution solution;
	int a[] = {2, 3, 6, 7};
	vector<int> vec(a, a + sizeof(a) / 4);
	vector< vector<int> > result = solution.combinationSum(vec, 7);
	for (auto it1 = result.begin(); it1 != result.end(); ++it1) {
		for (auto it2 = it1->begin(); it2 != it1->end(); ++it2) {
			cout << *it2 << ',';
		}
		cout << endl;
	}
	return 0;
}
