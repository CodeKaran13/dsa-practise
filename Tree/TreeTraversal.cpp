//
// Created by Karan Nandkar on 10/05/26.
//

/*
 * DFS Traversals
 */

#include <iostream>

#include "TreeNode.h"


void preorderTraversal(const TreeNode* root)
{
    if (root == nullptr)
        return;

    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(const TreeNode* root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(const TreeNode* root)
{
    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->val << " ";
}
