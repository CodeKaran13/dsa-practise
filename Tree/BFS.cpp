//
// Created by Karan Nandkar on 13/05/26.
//

#include <queue>
#include <vector>

#include "TreeNode.h"

std::vector<int> levelOrder(TreeNode* root)
{
    std::vector<int> result;
    if (root == nullptr)
        return result;

    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        const TreeNode* current = q.front();
        q.pop();
        result.push_back(current->val);
        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);
    }

    return result;
}

std::vector<std::vector<int>> levelOrderBFS(TreeNode* root)
{
    std::vector<std::vector<int>> result;
    if (root == nullptr)
        return result;

    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        const int levelSize = static_cast<int>(q.size());
        std::vector<int> currentLevel;
        for (int i = 0; i < levelSize; i++)
        {
            const TreeNode* current = q.front();
            q.pop();
            currentLevel.push_back(current->val);
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        result.push_back(currentLevel);
    }

    return result;
}
