/************************************************
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
I 1, V 5, X 10, L 50, C 100, D 500, M 1000
*************************************************/
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    string intToRoman(int num) { 
		int bits = 0, tens = 1, t = num;
		string result = "";
		char hash[][2] = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M'}};
		while (t /= 10) ++bits, tens *= 10;
		while (num) {
			t = num / tens;
			num %= tens;
			if (t > 0 && t < 4) {
				for (int i = 0; i < t; ++i) {
					result += hash[bits][0];
				}
			} else if (t == 4) {
				result = result + hash[bits][0] + hash[bits][1];
			} else if (t == 5) {
				result += hash[bits][1];
			} else if (t > 5 && t < 9) {
				result += hash[bits][1];
				for (int i = 0; i < t - 5; ++i) {
					result += hash[bits][0];
				}
			} else if (t == 9) {
				result = result + hash[bits][0] + hash[bits + 1][0];
			}
			--bits;
			tens /= 10;
		}
		return result;
    }
};
int main() {
	Solution solution;
	int num;
	while (cin >> num) {
		cout <<	solution.intToRoman(num) << endl;
	}
	return 0;
}
