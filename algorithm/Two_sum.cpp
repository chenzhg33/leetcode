#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> m;
		vector<int> result;
		int size = numbers.size();
		for (int i = 0; i < size; ++i) {
			if (m.find(numbers[i]) == m.end()) {
				m[target - numbers[i]] = i;
			} else {
				result.push_back(m[numbers[i]] + 1);
				result.push_back(i + 1);
				break;
			}
		}
		return result;
  }
};
int main() {
	Solution solution;
	int a[] = {2, 7, 11, 15};
	vector<int> vec(a, a + 4);
	vector<int> re = solution.twoSum(vec, 26);
	if (re.size() != 0) {
		cout << re[0] << ' ' << re[1] << endl;
	}
	return 0;
}
