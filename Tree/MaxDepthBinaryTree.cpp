//
// Created by Karan Nandkar on 04-06-2026.
//

#include <algorithm>
#include <queue>

#include "TreeNode.h"

int maxDepth(const TreeNode* root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + std::max(leftDepth, rightDepth);
}

int maxDepthBFS(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    std::queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
        const int levelSize = static_cast<int>(q.size());
        for (int i = 0; i < levelSize; i++)
        {
            const TreeNode* current = q.front();
            q.pop();
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        depth++;
    }
    return depth;
}
