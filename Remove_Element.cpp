/*********************************************************************
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*********************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int p = 0;
				for (int i = 0; i < n; ++i) {
					if (A[i] != elem) {
						A[p++] = A[i];
					}
				}
				return p;
    }
};
int main() {
	Solution solution;
	int elem;
	while (cin >> elem) {
		int a[] = {2, 3, 1, 3, 2, 4, 5, 10, 7, 7, 2};
		int len = solution.removeElement(a, sizeof(a) / 4, elem);
		for (int i = 0; i < len; ++i) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
