//
// Created by Karan Nandkar on 13/05/26.
//

#include <queue>
#include <vector>

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
};

std::vector<int> levelOrder(TreeNode* root)
{
    std::vector<int> result;
    if (root == nullptr) return result;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();

        result.push_back(current->value);

        if (current->left)
        {
            q.push(current->left);
        }

        if (current->right)
        {
            q.push(current->right);
        }
    }

    return result;
}

std::vector<std::vector<int>> levelOrderBFS(TreeNode* root)
{
    std::vector<std::vector<int>> result;
    if (root == nullptr) return result;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        std::vector<int> currentLevel;

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode* current = q.front();
            q.pop();

            currentLevel.push_back(current->value);

            if (current->left)
            {
                q.push(current->left);
            }

            if (current->right)
            {
                q.push(current->right);
            }
        }

        result.push_back(currentLevel);
    }

    return result;
}
