#pragma once

/*
名称：左叶子之和

描述：给定二叉树的根节点 root ，返回所有左叶子之和。

解题思路：递归：只有当前遍历的节点是父节点，才能判断其子节点是不是左叶子：判断左节点存在，并且没有左右子节点则返回其值。
*/

#include<iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class LeetCode0404 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        int leftvalue = 0;
        //左节点为叶子节点
        if (root->left && !root->left->left && !root->left->right)
        {
            leftvalue = root->left->val;
        }
        return leftvalue + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }

    void test()
    {
        TreeNode* root=new TreeNode(3);
        root->left =new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        std::cout << sumOfLeftLeaves(root);
    }
};