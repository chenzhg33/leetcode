/*******************************************
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
		int l = 0, r = height.size() - 1;
		int re = 0;
		while (l < r) {
			re = max(re, (r - l) * min(height[l], height[r]));
			if (height[l] < height[r]) {
				++l;
			} else {
				--r;
			}
		}
		return re;
    }
};
int main() {
	Solution solution;
	vector<int> vec;
	int n, h;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h;
		vec.push_back(h);
	}
	cout << solution.maxArea(vec);
	return 0;
}
