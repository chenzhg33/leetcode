#coding=utf-8
'''
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume duplicate exists in the array.
'''
def findHelper(num, l, r):
    while l < r and num[l] == num[l + 1]:
        l = l + 1
    while l < r and num[r] == num[r - 1]:
        r = r - 1
    if l == r:
        return num[l]
    if num[l] == num[r]:
        r = r - 1
    while l + 1 < r:
        m = (l + r) >> 1
        if num[m] > num[l] or num[m] == num[l]:
            if num[m] <= num[r]:
                return num[l]
            else:
                l = m + 1
        else:
            r = m
    return min(num[l], num[r])
class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        return findHelper(num, 0, len(num) - 1)
#num = [5, 6, 7, 0, 1, 2, 3, 4, 5]
num = [1, 2, 2, 2, 2, 0]
solution = Solution()
print solution.findMin(num)
