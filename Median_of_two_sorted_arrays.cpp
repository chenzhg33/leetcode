/****************************************
   Median of Two Sorted Arrays 
----There are two sorted arrays A and B of size m and n respectively. 
----Find the median of the two sorted arrays. 
----The overall run time complexity should be O(log (m+n)).

****Reference: http://blog.csdn.net/yutianzuijin/article/details/11499917
*****************************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
class Solution {
    public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
	    bool single = (m + n) & 1;
	    if (single) {
			return findKth(A, m, B, n, (m + n + 1) >> 1);
	    } else {
			return ((double)findKth(A, m, B, n, (m + n) >> 1)
				+ findKth(A, m, B, n, ((m + n) >> 1) + 1)) / 2;
	    }
	}
	int findKth(int A[], int m, int B[], int n, int k) {
	    if (m > n) {
			return findKth(B, n, A, m, k);
	    }
	    if (m == 0) {
			return B[k - 1];
	    }
	    if (k == 1) {
			return min(A[0], B[0]);
	    }
	    int ai = min(k / 2, m);
	    int bi = k - ai;
	    if (A[ai - 1] < B[bi - 1]) {
			return findKth(A + ai, m - ai, B, n, k - ai);
	    } else if (A[ai - 1] > B[bi - 1]) {
			return findKth(A, m, B + bi, n - bi, k - bi);
	    } else {
			return A[ai - 1];
	    }
	}
};
int main() {
    Solution solution;
    int A[] = {1, 5, 6, 9, 12, 19};
    int B[] = {2, 3, 4, 7, 8, 10, 11, 13, 14, 15, 16, 17, 18};
    int m = sizeof(A) / 4, n = sizeof(B) / 4;
    printf("%f\n", solution.findMedianSortedArrays(A, m, B, n));
    return 0;
}
/**********************************************************************
 * My Code, the worst complexity is O(n^2), which A like {1, 3, 5, 7, 9}
 * and B was like {2, 4, 6, 8}
 **********************************************************************

class Solution {
    public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
	    bool single = (m + n) & 1;
	    int need = ((m + n) >> 1) + 1;
	    int aindex = m - 1, bindex = n - 1;
	    int num1, num2;
	    while (true) {
		if (A[aindex] > B[bindex]) {
		    aindex = binary_search(A, aindex - 1, B[bindex]);
		    if (aindex + bindex < need - 2) {
			aindex = need - bindex - 2;
			return get_result(A, aindex, B, bindex, single);
		    }
		} else {
		    bindex = binary_search(B, bindex - 1, A[aindex]);
		    if (aindex + bindex < need - 2) {
			bindex = need - aindex - 2;
			return get_result(A, aindex, B, bindex, single);
		    }
		}
	    }

	}

	int binary_search(int a[], int r, int target) {
	    int l = 0, m;
	    while (l < r) {
		m = (l + r) >> 1;
		if (target <= a[m]) {
		    r = m;
		} else {
		    l = m + 1;
		}
	    }
	    return l - 1;
	}

	double get_result(int A[], int aindex, int B[], int bindex, bool single) {
	    if (single) {
		return max(A[aindex], B[bindex]);
	    } else {
		if (aindex == 0) {
		    if (A[aindex] < B[bindex - 1]) {
			return ((double)B[bindex] + B[bindex - 1]) / 2;
		    } else {
			return ((double)A[aindex] + B[bindex]) / 2;
		    }
		} else if (bindex == 0) {
		    if (B[bindex] < A[aindex - 1]) {
			return ((double)A[aindex] + A[aindex - 1]) / 2;
		    } else {
			return ((double)B[bindex] + A[aindex]) / 2;
		    }
		}
		int tmp[4] = { A[aindex - 1], A[aindex], B[bindex - 1], B[bindex]};
		sort(tmp, tmp + 4);
		return ((double)tmp[2] + tmp[3]) / 2;
	    }
	}

};
*********************************************************************/
