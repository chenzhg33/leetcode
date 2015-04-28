/****************************************************
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*****************************************************/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
		int len = s.length();
		char *buf = new char[(len << 1) + 2];
		char *tp = buf;
		*(tp++) = '#';
		for (int i = 0; i < len; ++i) {
			*(tp++) = s[i];
			*(tp++) = '#';
		}
		*tp = 0;
		len = (len << 1) + 2;
		int *p = new int[len], mlen = 1, next = 1, mid = 0;
		p[0] = 1;
		for (int i = 1; i < len; ++i) {
			if (next - i > 1) {
				p[i] = min(next - i, p[(mid << 1) - i]);
			} else {
				p[i] = 1;
			}
			while (buf[i - p[i]] == buf[i + p[i]] && i - p[i] >= 0
					&& i + p[i] < len) {
				++p[i];
			}
			if (i + p[i] > next) {
				next = i + p[i];
				mid = i;
			}
		}
		int pos = 0;
		for (int i = 1; i < len; ++i) {
			if (p[pos] < p[i]) {
				pos = i;
			}
		}
		int start = 0;
		if (pos & 1) {
			start = (pos - p[pos] + 1) / 2;
		} else {
			start = pos / 2 - (p[pos] - 1) / 2;
		}
		//printf("%d : %d\n", start, p[pos] - 1);
		delete []p;
		delete []buf;
		return s.substr(start, p[pos] - 1);
    }
};
int main() {
	string s;
	Solution solution;
	while (cin >> s) {
		cout << solution.longestPalindrome(s) << endl;
	}
	return 0;
}

