#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		const int M = 2147483647;
		const int N = -2147483648;
		int result = 0;
		int b;
		while (x != 0) {
			b = x % 10;
			if (b > M/10 || b < N/10) {
				return 0;
			}
			x /= 10;
			result *= 10;
			result += b;
		}
		return result;
   }
};
int main() {
	Solution solution;
	while (1) {
		int x;
		cin >> x;
		cout << solution.reverse(x) << endl;
	}
}
