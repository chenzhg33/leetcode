/***********************************************
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.
************************************************/
#include <stdio.h>
int maxProfit(int prices[], int n){
	if (n < 2) return 0;
	int sum = 0, max = 0;//INT_MAX;
	for (int i = 1; i < n; ++i) {
		sum += prices[i] - prices[i-1];
		if (sum < 0) {
			sum = 0;
			continue;
		}
		if (sum > max) {
			max = sum;
		}
	}
	return max;
}
int main() {
	int a[] = {2, 1};
	printf("%d\n", maxProfit(a, sizeof(a)/4));
	return 0;
}