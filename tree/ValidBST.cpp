//
// Created by Karan Nandkar on 13/05/26.
//


#include <limits>

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const int value) : value(value), left(nullptr), right(nullptr) {}
};

bool validate(const TreeNode* node, const long long minAllowed, const long long maxAllowed)
{
    if (node == nullptr) return true;

    if (node->value <= minAllowed || node->value >= maxAllowed) return false;

    return validate(node->left, minAllowed, node->value) && validate(node->right, node->value, maxAllowed);
}

bool isValidBST(TreeNode* root)
{
    return validate(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}
