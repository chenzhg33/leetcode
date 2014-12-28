/*********************************************
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*********************************************/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		int hash[100] = {0};
		hash['I'] = 1;
		hash['V'] = 5;
		hash['X'] = 10;
		hash['L'] = 50;
		hash['C'] = 100;
		hash['D'] = 500;
		hash['M'] = 1000;
		int len = s.length(), re = 0;
		for (int i = 0; i < len; ++i) {
			if (hash[s[i + 1]] > hash[s[i]]) {
				re -= hash[s[i]];
			} else {
				re += hash[s[i]];
			}
		}
		return re;
	}
};
int main() {
	Solution solution;
	string snum;
	while (cin >> snum) {
		cout << solution.romanToInt(snum) << endl;
	}
	return 0;
}
