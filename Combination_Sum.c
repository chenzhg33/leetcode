/****************************************************
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
****************************************************/
#include <stdio.h>
#include <stdlib.h>

int *result[1000];
int total;
int solution[1000];
int cols[1000];
void helper(int candidates[], int n, int target, int sum, int num, int cur) {
	//printf("sum : %d\n", sum);
	if (sum > target) return;
	solution[cur] = num;
	if (sum == target) {
		result[total] = (int*)malloc(sizeof(int) * (cur + 1));
		for (int i = 0; i <= cur; ++i) {
			//printf("%d ", solution[i]);
			result[total][i] = solution[i];
		}
		//printf("\n");
		cols[total] = cur + 1;
		++total;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (candidates[i] < num) continue;
		helper(candidates, n, target, sum + candidates[i], candidates[i], cur + 1);
	}
}
/**
 * Return an array of int arrays of size *returnSize.
 * The sizes of the int arrays are returned in *columnSizes.
 */
int **combinationSum(int candidates[], int n, int target, int **columnSizes, int *returnSize) {
    total = 0;
    for (int i = 0; i < n; ++i) {
    	helper(candidates, n, target, candidates[i], candidates[i], 0);
    }
    //printf("YES\n");
    *returnSize = total;
    *columnSizes = cols;
    return result;
}
int main() {
	while (1) {
	int n;
	int a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int target = 1;
	scanf("%d", &target);
	int **columns;
	int rows;
	int **result = combinationSum(a, n, target, columns, &rows);
	//printf("rows : %d\n", rows);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < (*columns)[i]; ++j) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	}
	return 0;
}