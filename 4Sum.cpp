/*****************************************************************
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
			sort(num.begin(), num.end());
			int size = num.size();
			int i, j, x, y, s;
			vector< vector<int> > result;
			bool flag = 0;
			for (i = 0; i < size; ++i) {
				if (i > 0 && num[i] == num[i-1]) continue;
				for (j = i + 1; j < size; ++j) {
					if ((j > 1 && num[j] == num[j-2]) || (num[j] == num[j-1] && num[i] != num[j])) continue;
					//cout << num[i] << ' ' << num[j] << endl;
					x = j + 1;
					y = size - 1;
					while (x < y) {
						s = num[i] + num[j] + num[x] + num[y];
						if (s == target) {
							vector<int> tmp;
							tmp.push_back(num[i]);
							tmp.push_back(num[j]);
							tmp.push_back(num[x]);
							tmp.push_back(num[y]);
							result.push_back(tmp);
							while (x < size - 1 && num[x] == num[x+1]) ++x;
							++x;
							while (y > 0 && num[y] == num[y-1]) --y;
							--y;
						} else if (s > target) {
							--y;
						} else {
							++x;
						}
					}
				}
			}
			return result;
    }
};
int main() {
	int a[] = {0,-1,0,1,-2,-5,3,5,0};
	vector<int> num(a, a + sizeof(a) / 4);
	Solution solution;
	vector< vector<int> > result = solution.fourSum(num, 6);
	for (auto it = result.begin(); it != result.end(); ++it) {
		for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
			cout << *it2 << ',';
		}
		cout << endl;
	}
	return 0;
}
