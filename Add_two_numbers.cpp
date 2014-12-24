/***********************************************************
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		string s1 = convertListNodeToStringNumber(l1);
		string s2 = convertListNodeToStringNumber(l2);
		string result = addStringNumbers(s1, s2);
		return convertStringNumberToListNode(result);
    }
	string convertListNodeToStringNumber(ListNode* ls) {
		string result;
		while (ls) {
			result = (char)(ls->val + '0') + result; //reverse order 2->4->3 means the number 342
			ls = ls->next;
		}
		return result;
	}
	ListNode* convertStringNumberToListNode(string& s) {
		ListNode* ls, **current;
		current = &ls;
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			*current = new ListNode(s[i] - '0');
			current = &(*current)->next;
		}
		*current = NULL;
		return ls;
	}
	string addStringNumbers(string& s1, string& s2) {
		if (s1.length() < s2.length()) {
			return addStringNumbers(s2, s1);
		}
		int len = s1.length();
		int zero = len - s2.length();
		while (zero--) {
			s2 = '0' + s2;
		}
		int carry = 0, bit;
		string result;
		for (int i = len - 1; i >= 0; --i) {
			bit = s1[i] + s2[i] - '0' + carry;
			if (bit > '9') {
				carry = 1;
				result += (char)(bit - 10);
			} else {
				carry = 0;
				result += (char)bit;
			}
		}
		if (carry == 1) {
			return result + "1";
		}
		return result;
	}
};
void printListNode(ListNode* rt) {
	while (rt) {
		cout << rt->val;
		rt = rt->next;
	}
	cout << endl;
}
ListNode* convertStringNumber(string& s) {
	ListNode* ls, **current;
	current = &ls;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		*current = new ListNode(s[i] - '0');
		current = &(*current)->next;
	}
	*current = NULL;
	return ls;
}
int main() {
	Solution solution;
	string s1, s2;
	while (cin >> s1 >> s2) {
		ListNode* l1 = convertStringNumber(s1);
		ListNode* l2 = convertStringNumber(s2);
		printListNode(solution.addTwoNumbers(l1, l2));
	}
	return 0;
}
