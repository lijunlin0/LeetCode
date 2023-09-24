#pragma once
#include<iostream>

/*

名称：二叉树的最小深度

描述：给定一个二叉树，找出其最小深度。最小深度是从根节点到最近叶子节点的最短路径上的节点数量。说明：叶子节点是指没有子节点的节点。

解题思路：与求最大深度不同点：当左孩子和右孩子都没有节点时才是深度，然后递归查找最小深度
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class LeetCode0111 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr)
        {
            return minDepth(root->right) + 1;
        }
        if (root->right == nullptr)
        {
            return minDepth(root->left) + 1;
        }
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }

    void test()
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        std::cout<<minDepth(root);
    }
};