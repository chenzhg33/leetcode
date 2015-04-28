/******************************************************
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*******************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int size = num.size();
        int times = 0, result;
        for (int i = 0; i < size; ++i) {
            if (times == 0) {
                result = num[i];
                times = 1;
            } else {
                if (num[i] == result) {
                    ++times;
                } else {
                    --times;
                }
            }
        }
        
        return result;
    }
};
int main() {
	int a[] = {1, 2, 1, 1, 3, 1, 5};
	vector<int> vec(a, a + sizeof(a));
	Solution solution;
	cout << solution.majorityElement(vec);
	return 0;
}
