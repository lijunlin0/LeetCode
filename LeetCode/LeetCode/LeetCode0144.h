#pragma once
/*
名称:二叉树的前序遍历

描述：给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

解题思路：创建一个函数，用vector存储递归遍历的值
*/

#include<iostream>
#include<vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class LeetCode0144 {
public:
    //递归函数
    void help(TreeNode* root, std::vector<int>& nums)
    {
        if (root == nullptr)
        {
            return;
        }
        nums.push_back(root->val);
        help(root->left, nums);
        help(root->right, nums);
    }
    std::vector<int> preorderTraversal(TreeNode* root) 
    {
        //用于存储遍历值
        std::vector<int> nums;
        help(root, nums);
        return nums;
    }

    void test()
    {
        TreeNode* root = new TreeNode(1);
        root->right = new TreeNode(3);
        root->right->left = new TreeNode(2);
        for (int i = 0; i < 3; i++)
        {
            std::cout << preorderTraversal(root)[i];
        }
    }
};