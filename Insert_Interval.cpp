/************************************************************
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*************************************************************/
#include <iostream>
#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {			
			int size = intervals.size();
			vector<Interval> re;
			if (size == 0) {
				re.push_back(newInterval);
				return re;
			}
			int l =  binary_start(intervals, newInterval.start);
			int r =  binary_end(intervals, newInterval.end);
			if (l == -1 && r == size) {
				re.push_back(newInterval);
				return re;
			} else if (l == -1) {
				if (newInterval.end < intervals[r].start) {
					re.push_back(newInterval);
					re.push_back(intervals[r]);
				} else {
					re.push_back(Interval(newInterval.start, intervals[r].end));
				}
				for (int i = r + 1; i < size; ++i) {
					re.push_back(intervals[i]);
				}
			} else if (r == size) {
				for (int i = 0; i < l; ++i) {
					re.push_back(intervals[i]);
				}
				if (newInterval.start > intervals[l].end) {
					re.push_back(intervals[l]);
					re.push_back(newInterval);
				} else {
					re.push_back(Interval(intervals[l].start, newInterval.end));
				}
			} else {
				for (int i = 0; i < l; ++i) {
					re.push_back(intervals[i]);
				}
				if (newInterval.start > intervals[l].end) {
					re.push_back(intervals[l]);
					if (newInterval.end < intervals[r].start) {
						re.push_back(newInterval);
						re.push_back(intervals[r]);
					} else {
						re.push_back(Interval(newInterval.start, intervals[r].end));
					}
				} else {
					if (newInterval.end < intervals[r].start) {
						re.push_back(Interval(intervals[l].start, newInterval.end));
						re.push_back(intervals[r]);
					} else {
						re.push_back(Interval(intervals[l].start, intervals[r].end));
					}
				}
				for (int i = r + 1; i < size; ++i) {
					re.push_back(intervals[i]);
				}
			}
			return re;
    }

		int binary_start(vector<Interval> &intervals, int target) {
			int l = 0, r = intervals.size() - 1, m;
			if (r == -1) return -1;
			if (intervals[0].start > target) return -1;
			while (l < r) {
				m = (l + r) >> 1;
				if (target <= intervals[m].start) {
					r = m;
				} else {
					l = m + 1;
				}
			}
			return intervals[l].start <= target ? l : l - 1;
		}
		int binary_end(vector<Interval> &intervals, int target) {
			int l = 0, r = intervals.size() - 1, m;
			if (r == -1) return -1;
			if (intervals[r].end < target) return r + 1;
			while (l < r) {
				m = (l + r + 1) >> 1;
				if (target >= intervals[m].end) {
					l = m;
				} else {
					r = m - 1;
				}
			}
			return intervals[l].end >= target ? l : l + 1;
		}
};
int main() {
	Solution solution;
	int a[][2] = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
	//int a[][2] = {{1, 5}};
	vector<Interval> intervals;
	for (int i = 0; i < sizeof(a) / 8; ++i) {
		intervals.push_back(Interval(a[i][0], a[i][1]));
	}
	Interval inter;
	while (cin >> inter.start >> inter.end) {
		vector<Interval> re = solution.insert(intervals, inter);
		for (int i = 0; i < re.size(); ++i) {
			cout << '[' << re[i].start << ',' << re[i].end << ']' << ' ';
		}
		cout << endl;
	}
	return 0;
}
