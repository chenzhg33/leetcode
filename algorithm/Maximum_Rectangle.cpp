/***************************************
Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing all ones and return its area.
***************************************/
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
			if (matrix.size() == 0) return 0;
			int rows = matrix.size(), cols = matrix[0].size();
			int A[rows + 2][cols + 2];
			memset(A, 0, sizeof(A));
			int x, y;
			int mx = -100000;
			for (int i = 1; i <= rows; ++i) {
				for (int j = 1; j <= cols; ++j) {
					if (matrix[i-1][j-1] == '1') {
						A[i][j] = A[i-1][j] + 1;
					}
				}
				mx = max(mx, rowMax(A[i], cols + 1));
			}
			for (int i = 1; i <= rows; ++i) {
			}
			return mx;
    }
		int rowMax(int a[], int n) {
			stack<int> st;
			int mx = -1000000;
			for (int i = 1; i <= n;) {
				if (st.empty() || a[i] > a[st.top()]) {
					st.push(i);
					++i;
				} else {
					int index = st.top();
					st.pop();
					mx = max(mx, a[index] * (st.empty() ? i - 1: i - st.top() - 1));
				}
			}
			return mx;
		}




};
int main() {
	Solution solution;
	//int a[][8] = {{0, 1, 0, 1, 1, 0, 0, 1},
	//							{1, 1, 1, 1, 0, 1, 1, 1},
	//							{0, 1, 1, 1, 1, 1, 0, 1},
	//							{1, 1, 1, 1, 0, 1, 1, 1},
	//							{0, 1, 1, 0, 1, 1, 1, 1}};
	int a[][8] = {{0, 0, 0, 0, 0, 0, 1, 0},
								{0, 0, 0, 0, 0, 0, 1, 0},
								{0, 0, 0, 0, 0, 0, 1, 0},
								{0, 0, 0, 0, 0, 1, 1, 1},
								{1, 1, 1, 1, 1, 1, 1, 1},
								{0, 0, 0, 0, 0, 1, 1, 1}};
	vector< vector<char> > vec;
	for (int i = 0; i < 6; ++i) {
		vector<char> tmp;
		for (int j = 0; j < sizeof(a[0]) / 4; ++j) {
			tmp.push_back(a[i][j] + '0');
		}
		vec.push_back(tmp);
	}
	cout << solution.maximalRectangle(vec) << endl;
	return 0;
}
