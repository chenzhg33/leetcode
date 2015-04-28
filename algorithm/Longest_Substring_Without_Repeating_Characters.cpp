/**********************************************************
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
***********************************************************/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int cnt = 0, mlen = 0, visit[256], len = s.length(); 
		int begin = 0;
		memset(visit, -1, 1024);
		for (int i = 0; i < len; ++i) {
			if (visit[s[i]] == -1 || visit[s[i]] < begin) {
				cnt++;
				mlen = max(mlen, cnt);
			} else {
				cnt = i - visit[s[i]];
				begin = visit[s[i]] + 1;
			}
			visit[s[i]] = i;
		}
		return mlen;
    }
};
int main() {
	string s;
	Solution solution;
	while (cin >> s) {
		cout << solution.lengthOfLongestSubstring(s) << endl;
	}
	return 0;
}

