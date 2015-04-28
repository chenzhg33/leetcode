#coding=utf-8
'''
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
'''
def findHelper(num, l, r):
    while l + 1 < r:
        m = (l + r) >> 1
        if num[m] > num[l] and num[m] > num[r]:
            l = m + 1
        elif num[m] < num[l] and num[m] < num[r]:
            r = m
        else:
            return num[l]
    return min(num[l], num[r])
class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        return findHelper(num, 0, len(num) - 1)
num = [6, 7, 0, 1, 2, 3, 4, 5]
solution = Solution()
print solution.findMin(num)
