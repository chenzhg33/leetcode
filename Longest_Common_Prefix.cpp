/*****************************************
Write a function to find the longest common prefix string amongst an array of strings.
*****************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {        
		int size = strs.size();
		if (size == 0) return "";
		if (size == 1) return strs[0];
		string result("");
		int i, j, min_len = 1 << 30;
		for (i = 0; i < size; ++i) {
			min_len = min(min_len, (int)strs[i].length());
		}
		for (i = 0; i < min_len; ++i) {
			char ch = strs[0][i];
			for (j = 1; j < size; ++j) {
				if (strs[j][i] != ch) {
					goto next;
				}
			}
			result += ch;
		}
next:
		return result;
    }
};
int main() {
	Solution solution;
	int n;
	string s;
	vector<string> vec;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		vec.push_back(s);
	}
	cout << solution.longestCommonPrefix(vec) << endl;
	return 0;
}
