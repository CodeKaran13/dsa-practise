//
// Created by Karan Nandkar on 13/05/26.
//


#include <limits>

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

bool validate(TreeNode* node, long long minValue, long long maxValue)
{
    if (node == nullptr) return true;
    if (node->value <= minValue || node->value >= maxValue) return false;

    return validate(node->left, minValue, node->value) && validate(node->right, node->value, maxValue);
}

bool isValidBST(TreeNode* root)
{
    return validate(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
}
