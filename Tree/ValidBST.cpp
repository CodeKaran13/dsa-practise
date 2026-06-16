//
// Created by Karan Nandkar on 13/05/26.
//


#include <limits>

#include "TreeNode.h"


bool Validate(const TreeNode* node, long long minValue, long long maxValue)
{
    if (node == nullptr)
        return true;

    if (node->val <= minValue || node->val >= maxValue)
        return false;

    return Validate(node->left, minValue, node->val) && Validate(node->right, node->val, maxValue);
}

bool IsValidBST(const TreeNode* root)
{
    return Validate(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
}
