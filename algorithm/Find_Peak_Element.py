#coding=utf-8
'''
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
'''
class Solution:
    # @param num, a list of integer
    # @return an integer
    def findPeakElement(self, num):
        l = 0
        r = len(num) - 1
        while (l < r):
            mid1 = (l + r) / 2
            mid2 = mid1 + 1;
            if num[mid1] < num[mid2]:
                l = mid2
            else:
                r = mid1
        return l
solution = Solution()
num = [1, 2, 3, 1]
print solution.findPeakElement(num)
