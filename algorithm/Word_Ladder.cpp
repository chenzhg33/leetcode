/**********************************************************
Given two words (start and end), and a dictionary, 
find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
************************************************************/
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int N = 10000;
const int INF = 1 << 30;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
			mp.clear();
			for (int i = 0; i < N; ++i) {
				vec[i].clear();
			}
			int cnt = 0;
			for (auto it = dict.begin(); it != dict.end(); ++it) {
				mp[*it] = cnt;
				words[cnt++] = *it;
			}
			len = start.length();
			if (mp.find(start) == mp.end()) {
				mp[start] = cnt;
				words[cnt++] = start;
			}
			if (mp.find(end) == mp.end()) {
				mp[end] = cnt;
				words[cnt++] = end;
			}
			first = mp[start];
			last = mp[end];
			for (int i = 0; i < cnt; ++i) {
				for (int j = 0; j < len; ++j) {
					string ss = words[i];
					for (char ch = 'a'; ch <= 'z'; ++ch) {
						if (ch == words[i][j]) {
							continue;
						}
						ss[j] = ch;
						auto it = mp.find(ss);
						if (it != mp.end()) {
							vec[i].push_back(it->second);
						}
					}
				}
			}
			int dis[N];
			fill_n(dis, cnt, INF);
			dis[first] = 0;
			memset(visit, 0, sizeof(visit));
			int min_pos = first;
			int min_value = INF;
			for (int i = 0; i < cnt; ++i) {
				min_value = INF;
				for (int j = 0; j < cnt; ++j) {
					if (!visit[j] && dis[j] < min_value) {
						min_pos = j;
						min_value = dis[j];
					}
				}
				cout << "min: " << min_pos << endl;
				if (min_pos == last) {
					return dis[last] + 1;
				}
				visit[min_pos] = true;
				for (auto it = vec[min_pos].begin(); it != vec[min_pos].end(); ++it) {
					if (!visit[*it] && dis[*it] > dis[min_pos] + 1) {
						dis[*it] = dis[min_pos] + 1;
					}
				}
			}
			return 0;
		}
private:
		bool visit[N];
		vector<int> vec[N];
		string words[N];
		int first, last;
		int len, min_dis;
		map<string, int> mp;
};
int main() {
	Solution solution;
	string ss[] = {"hot","dot","dog","lot", "log"};
	unordered_set<string> dict(ss, ss + 5);
	string s, e;
	while (cin >> s >> e) {
		cout << solution.ladderLength(s, e, dict) << endl;
	}
	return 0;
}
