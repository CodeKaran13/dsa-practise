//
// Created by Karan Nandkar on 10/06/26.
//

#ifndef DSA_PRATISE_TREENODE_H
#define DSA_PRATISE_TREENODE_H


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


#endif //DSA_PRATISE_TREENODE_H
