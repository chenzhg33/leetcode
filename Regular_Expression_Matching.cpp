/**************************************************
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
****************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		if (s == NULL || p == NULL) return false;
		if (*p == 0) return *s == 0;
		if (*s != 0 && *p == '.' || *p == *s) {
			if (*(p+1) == '*')
				return isMatch(s + 1, p) || isMatch(s, p + 2);
			return isMatch(s + 1, p + 1);
		} else if (*(p + 1) == '*') {
				return isMatch(s, p + 2);
		}
		return false;
    }
};
int main() {
	Solution solution;
	char s1[100], s2[100];
	while (cin >> s1 >> s2) {
		if (solution.isMatch(s1, s2)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
