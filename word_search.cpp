/***************************************************
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*****************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
			len = word.length(), rows = board.size(), cols = board[0].size();
			str = word;
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < cols; ++j) {
					if (word[0] == board[i][j]) {
						memset(visit, 0, sizeof(visit));
						visit[i][j] = true;
						if (dfs(board, i, j, 1)) {
							return true;
						}
					}
				}
			}
			return false;
    }
		bool dfs(vector< vector<char> > &board, int cur_row, int cur_col, int cur_len) {
			if (cur_len == len) {
				return true;
			}
			for (int i = 0; i < 4; ++i) {
					int new_row = cur_row + dir[i][0];
					int new_col = cur_col + dir[i][1];
					if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols 
							&& !visit[new_row][new_col] && board[new_row][new_col] == str[cur_len]) {
						visit[new_row][new_col] = true;
						if (dfs(board, new_row, new_col, cur_len + 1)) {
							return true;
						}
						visit[new_row][new_col] = false;
					}
			}
			return false;
		}
private:
		bool visit[100][100];
		int len, cols, rows;
		string str;
};
int main() {
	string ss[] = { "ABCE", "SFCS", "ADEE" };
	vector< vector<char> > board;
	for (int i = 0; i < 3; ++i) {
		vector<char> tmp;
		for (int j = 0; j < 4; ++j) {
			tmp.push_back(ss[i][j]);
		}
		board.push_back(tmp);
	}
	string test;
	Solution solution;
	while (cin >> test) {
		if (solution.exist(board, test)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

