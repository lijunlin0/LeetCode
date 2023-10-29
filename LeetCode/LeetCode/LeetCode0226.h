#pragma once

/*
名称：翻转二叉树

描述：给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

解题思路：递归交换左右指针
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

class LeetCode0226 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    void test()
    {
        TreeNode* head = new TreeNode(1);
        head->left = new TreeNode(2);
        head->right = new TreeNode(3);
        head->left->left = new TreeNode(4);
        head->left->right = new TreeNode(5);
        head->right->left = new TreeNode(6);
        invertTree(head);
 
        std::cout << head->val<<' ';
        std::cout << head->left->val << ' ';
        std::cout << head->right->val << ' ';
        std::cout << head->left->right->val << ' ';
        std::cout << head->right->left->val << ' ';
        std::cout << head->right->right->val << ' ';

    }
};