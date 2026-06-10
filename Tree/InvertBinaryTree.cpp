//
// Created by Karan Nandkar on 10/06/26.
//

/**
 * NOTE: Swap left and right nodes
 */

#include <algorithm>

#include "TreeNode.h"

TreeNode* InvertTree(TreeNode* root)
{
    if (root == nullptr)
        return nullptr;

    std::swap(root->left, root->right);

    InvertTree(root->left);
    InvertTree(root->right);

    return root;
}
