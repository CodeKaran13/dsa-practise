//
// Created by Karan Nandkar on 10/06/26.
//

/**
 * Given two binary trees:
 * TreeNode* p
 * TreeNode* q
 *
 * Return true if both trees have
 * Same structure
 * Same values
 */

#include "TreeNode.h"

bool IsSameTree(const TreeNode* p, const TreeNode* q)
{
    if (p == nullptr && q == nullptr)
        return true;

    if (p == nullptr || q == nullptr)
        return false;

    if (p->val != q->val)
        return false;

    return IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right);
}
