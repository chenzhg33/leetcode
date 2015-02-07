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
#include <queue>
using namespace std;
const int N = 10000;
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
			result.clear();
			if (start == end) {
				vector<string> tmp;
				tmp.push_back(start);
				tmp.push_back(end);
				result.push_back(tmp);
				return result;
			}
			mp.clear();
			for (int i = 0; i < N; ++i) {
				vec[i].clear();
				parent[i].clear();
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
			vector<int> cur, next;
			cur.push_back(first);
			bool visit[N] = {0};
			bool cur_visit[N] = {0};
			visit[first] = true;
			cur_visit[first] = true;
			bool unfinish = true;
			while (unfinish) {
				next.clear();
				int cnt = 0, a[N];
				if (cur.size() == 0) break;
				for (auto i = cur.begin(); i != cur.end(); ++i) {
					//cout << words[*i] << ' ';
					for (auto it = vec[*i].begin(); it != vec[*i].end(); ++it) {
						if (!visit[*it]) {
							parent[*it].push_back(*i);
							//cout << words[*it] << " parent is " << words[*i] << endl;
							if (!cur_visit[*it]) {
								cur_visit[*it] = true;
								a[cnt++] = *it;
								next.push_back(*it);
							}
						}
						if (*it == last) {
							unfinish = false;
							continue;
						}
					}
				}
				for (int k = 0; k < cnt; ++k) {
					visit[a[k]] = true;
				}
				//cout << endl;
				cur = next;
			}
			path.clear();
			dfs(last);
			if (result.size() == 0) { cout << "empty." << endl; }
			for (int i = 0; i < result.size(); ++i) {
				for (int j = 0; j < result[i].size(); ++j) {
					cout << result[i][j] << ' ';
				}
				cout << endl;
			}
			return result;
		}
		void dfs(int p) {
			path.push_back(p);
			if (p == first) {
				vector<string> tmp;
				for (auto it = path.rbegin(); it != path.rend(); ++it) {
					tmp.push_back(words[*it]);
				}
				result.push_back(tmp);
				path.pop_back();
				return;
			}
			for (auto it = parent[p].begin(); it != parent[p].end(); ++it) {
				dfs(*it);
			}
			path.pop_back();
		}

private:
		vector<int> parent[N];
		vector<int> vec[N];
		string words[N];
		int first, last;
		int len, min_dis;
		map<string, int> mp;
		vector< vector<string> > result;
		vector<int> path;
};
int main() {
	Solution solution;
	string ss[] = {"hot", "dog"};
	//string ss[] = {"hot","dot","dog","lot","log"};
	unordered_set<string> dict(ss, ss + 2);
	string s, e;
	while (cin >> s >> e) {
		solution.findLadders(s, e, dict);
	}
	return 0;
}
