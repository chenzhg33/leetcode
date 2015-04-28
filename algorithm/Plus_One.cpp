/********************************************
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
********************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
			int carry = 1;
			for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
				int tmp = *it + carry;
				if (tmp > 9) {
					*it = tmp - 10;
					carry = 1;
				} else {
					*it = tmp;
					carry = 0;
					break;
				}
			}
			if (carry == 1) {
				digits.insert(digits.begin(), 1);
			}
			return digits;
    }
};
int main() {
	Solution solution;
	int a[] = {0};
	vector<int> digits(a, a + sizeof(a)/4);
	solution.plusOne(digits);
	return 0;
}
