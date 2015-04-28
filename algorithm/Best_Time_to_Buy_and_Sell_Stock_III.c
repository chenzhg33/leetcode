/***********************************************
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
************************************************/
#include <stdio.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize) {
	int leftmax[pricesSize], rightmax[pricesSize];
	memset(leftmax, 0, sizeof(leftmax));
	memset(rightmax, 0, sizeof(rightmax));
	int nn = prices[0];
	int i;
	for (i = 1; i < pricesSize; ++i) {
		if (nn > prices[i]) nn = prices[i];
		leftmax[i] = prices[i] - nn;
		if (leftmax[i] < leftmax[i-1])
			leftmax[i] = leftmax[i-1];
	}
	int mm = prices[pricesSize-1];
	for (i = pricesSize - 2; i >= 0; --i) {
		if (mm < prices[i]) mm = prices[i];
		rightmax[i] = mm - prices[i];
		if (rightmax[i] < rightmax[i-1])
			rightmax[i] = rightmax[i-1];
	}
	int mx = 0;
	for (i = 0; i < pricesSize; ++i) {
		if (mx < leftmax[i] + rightmax[i])
			mx = leftmax[i] + rightmax[i];
	}
	return mx;
}
int main() {
	int a[] = {2, 1};
	printf("%d\n", maxProfit(a, sizeof(a)/4));
	return 0;
}
