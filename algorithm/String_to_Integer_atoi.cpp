/************************************************************
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.
**************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdio>
using namespace std;
class Solution {
public:
    int atoi(const char *p) {
		if (p == NULL || *p == 0) {
			return 0;
		}
		int result = 0;
		bool negative = false;
		while (*p == ' ') {
			++p;
		}
		if (*p == '+') {
			++p;
		} else if (*p == '-') {
			negative = true;
			++p;
		}
		while (*p != 0) {
			if (*p >= '0' && *p <= '9') {
				if (negative) {
					if (-result < (INT_MIN + *p - '0') / 10) {
						return INT_MIN;
					}
				} else {
					if (result > (INT_MAX - (*p - '0')) / 10) {
						return INT_MAX;
					}
				}
				result = result * 10 + *p - '0';
			} else {
				break;
			}
			++p;
		}
		return negative ? -result : result;
    }
};
int main() {
	char buf[100];
	Solution solution;
	while (fgets(buf, 90, stdin) != NULL) {
		buf[strlen(buf)-1] = 0;
		cout << solution.atoi(buf) << endl;
	}
	return 0;
}
