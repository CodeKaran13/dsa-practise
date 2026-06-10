//
// Created by Karan Nandkar on 13/05/26.
//


#include <limits>

#include "TreeNode.h"


bool validate(const TreeNode* node, long long minValue, long long maxValue)
{
    if (node == nullptr) return true;
    if (node->val <= minValue || node->val >= maxValue) return false;

    return validate(node->left, minValue, node->val) && validate(node->right, node->val, maxValue);
}

bool isValidBST(const TreeNode* root)
{
    return validate(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
}
