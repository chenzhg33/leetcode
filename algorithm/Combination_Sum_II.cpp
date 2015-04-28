/****************************************************
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
****************************************************/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &vec, int t) {
			target = t;
			memset(visit, 0, sizeof(visit));
			sort(vec.begin(), vec.end(), cmp());
			bool visit2[1000];
			memset(visit2, 0, sizeof(visit2));
			for (int i = 0; i < vec.size(); ++i) {
				if (visit2[vec[i]]) continue;
				visit2[vec[i]] = true;
				visit[i] = true;
				dfs(vec, vec[i], 0, vec[i]);
				visit[i] = false;
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
			bool visit2[1000];
			memset(visit2, 0, sizeof(visit2));
			for (int i = 0; i < vec.size(); ++i) {
				if (vec[i] < cur) break;
				if (visit[i]) continue;
				if (visit2[vec[i]]) continue;
				visit2[vec[i]] = true;
				visit[i] = true;
				dfs(vec, vec[i], index, sum + vec[i]);
				visit[i] = false;
			}
		}
private:
		vector< vector<int> > result;
		int target;
		int path[1000];
		bool visit[1000];
};
int main() {
	Solution solution;
	int a[] = {10, 1, 2, 7, 6, 1, 5};
	vector<int> vec(a, a + sizeof(a) / 4);
	vector< vector<int> > result = solution.combinationSum(vec, 8);
	for (auto it1 = result.begin(); it1 != result.end(); ++it1) {
		for (auto it2 = it1->begin(); it2 != it1->end(); ++it2) {
			cout << *it2 << ',';
		}
		cout << endl;
	}
	return 0;
}
