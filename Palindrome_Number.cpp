/*****************************************************
Determine whether an integer is a palindrome. Do this without extra space.
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
******************************************************/
#include <iostream>
class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) return false;
		long long re = 0;
		int tmp = x;
		while (x) {
			re = re * 10 + x % 10;
			x /= 10;
		}
		return (long long)tmp == re;
    }
};
int main() {
	int k;
	Solution solution;
	while (std::cin >> k) {
		if (solution.isPalindrome(k)) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}

}
