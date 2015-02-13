/****************************************************
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
****************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
			if (height.size() == 0) return 0;
			height.insert(height.begin(), -1);
			height.push_back(0);
			stack<int> st;
			st.push(0);
			int mx = 0;
			for (int i = 1; i < height.size(); ++i) {
				if (height[i] > height[st.top()]) {
					st.push(i);
				} else if (height[i] == height[st.top()]) {
					st.pop();
					st.push(i);
				} else {
					int index = st.top();
					st.pop();
					mx = max(mx, height[index] * (i - st.top() - 1));
					--i;
				}
			}
			return mx;
    }
};
int main() {
	Solution solution;
	int a[] = {2, 1, 5, 6, 2, 3};
	vector<int> height(a, a + sizeof(a) / 4);
	cout << solution.largestRectangleArea(height);
	return 0;
}

