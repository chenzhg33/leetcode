/************************************************
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_set<int> st(num.begin(), num.end());
		int sum, mx = -1000;
		while (!st.empty()) {
			auto it = st.begin();
			int i = *it, tmp = *it;
			sum = 1;
			st.erase(st.begin());
			while (!st.empty() && (it = st.find(++tmp)) != st.end()) {
				++sum;
				st.erase(it);
			}
			tmp = i;
			while (!st.empty() && (it = st.find(--tmp)) != st.end()) {
				++sum;
				st.erase(it);
			}
			mx = max(mx, sum);
		}
		return mx;
	}
};
int main() {
	Solution solution;
	int a[] = {100, 4, 200, 1, 3, 2};
	vector<int> num(a, a + sizeof(a) / 4);
	cout << solution.longestConsecutive(num);
	return 0;
}
