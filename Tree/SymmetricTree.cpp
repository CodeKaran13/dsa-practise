//
// Created by Karan Nandkar on 10/06/26.
//


#include "TreeNode.h"

bool IsMirror(const TreeNode* left, const TreeNode* right)
{
    if (left == nullptr && right == nullptr)
        return true;

    if (left == nullptr || right == nullptr)
        return false;

    if (left->val != right->val)
        return false;

    return IsMirror(left->left, right->right) && IsMirror(left->right, right->left);
}

bool IsSymmetric(const TreeNode* root)
{
    if (root == nullptr)
        return true;

    return IsMirror(root->left, root->right);
}
