/*************************************************
The string "PAYPALISHIRING" is written in a zigzag pattern 
on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**************************************************/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
		if (nRows == 1) {
			return s;
		}
		int len = s.length();
		int size = (len << 1) / nRows;
		char* res[nRows];
		int cnt[nRows];
		memset(cnt, 0, sizeof(cnt));
		int step = 1, row = 0;
		for (int i = 0; i < nRows; ++i) {
			res[i] = new char[size];
		}
		for (int i = 0; i < len; ++i) {
			res[row][cnt[row]++] = s[i];
			row += step;
			if (row == 0) {
				step = 1;
			} else if (row == nRows - 1) {
				step = -1;
			}
		}
		char buf[len + 1];
		char *tmp = buf;
		for (int i = 0; i < nRows; ++i) {
			memcpy(tmp, res[i], cnt[i]);
			tmp += cnt[i];
		}
		for (int i = 0; i < nRows; ++i) {
			delete []res[i];
		}
		return string(buf, len);
    }
};
int main() {
	string s;
	int row;
	Solution solution;
	while (cin >> s >> row) {
		cout << solution.convert(s, row) << endl;
	}
	return 0;
}

