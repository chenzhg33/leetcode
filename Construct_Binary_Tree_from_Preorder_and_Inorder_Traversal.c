/**********************************************************
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
struct TreeNode *buildTree(int *preorder, int *inorder, int n) {
	if (n == 0) return NULL;
	struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = *preorder;
	int *find = inorder;
	while (*(find++) != root->val) ;
	int nleft = find - inorder - 1;
	root->left = buildTree(preorder + 1, inorder, nleft);
	root->right = buildTree(preorder + nleft + 1, find, n - nleft - 1);
	return root;
}
void ps(struct TreeNode *root) {
	if (root == NULL) return;
	ps(root->left);
	ps(root->right);
	printf("%d", root->val);
}

int main() {
	int inorder[] = {2, 4, 1, 5, 3, 6};
	int preorder[] = {1, 2, 4, 3, 5, 6};
	struct TreeNode *root = buildTree(preorder, inorder, sizeof(inorder) / 4);
	ps(root);
	return 0;
}
