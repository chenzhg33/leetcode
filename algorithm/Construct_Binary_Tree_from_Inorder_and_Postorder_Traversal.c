/**********************************************************
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:h
You may assume that duplicates do not exist in the tree.
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
struct TreeNode *buildTree(int *inorder, int *postorder, int n) {
	if (n == 0) return NULL;
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	int *begin = inorder;
	node->val = *(postorder + n - 1);
	while (*begin != node->val) {
		++begin;
	}
	int nleft = begin - inorder;
	//printf("%d\n", nleft);
	node->left = buildTree(inorder, postorder, nleft);
	node->right = buildTree(begin + 1, postorder + nleft, n - nleft - 1);
	return node;
}
void ps(struct TreeNode *root) {
	if (root == NULL) return;
	printf("%d", root->val);
	ps(root->left);
	ps(root->right);
}

int main() {
	int inorder[] = {2, 4, 1, 5, 3, 6};
	int postorder[] = {4, 2, 5, 6, 3, 1};
	struct TreeNode *root = buildTree(inorder, postorder, sizeof(inorder) / 4);
	ps(root);
	return 0;
}
