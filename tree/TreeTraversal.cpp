//
// Created by Karan Nandkar on 10/05/26.
//

#include <iostream>

struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}

	std::cout << root->value << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void inorderTraversal(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}

	inorderTraversal(root->left);
	std::cout << root->value << " ";
	inorderTraversal(root->right);
}

void postorderTraversal(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}

	postorderTraversal(root->left);
	postorderTraversal(root->right);
	std::cout << root->value << " ";
}
