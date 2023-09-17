#pragma once
/*
名称：二叉树的中序遍历

描述：
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

解题思路：递归。
*/

#include<vector>
#include<iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class LeetCode0094 {
public:
    //递归保存数据
    void inorder(TreeNode* root, std::vector<int>& nums) 
    {
        //空结点退出
        if (!root)
        {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    //返回数据
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        std:: vector<int> nums;
        inorder(root, nums);
        return nums;
    }

    void test()
    {
        TreeNode* root = new TreeNode(1);
        root->right = new TreeNode(3);
        root->right->left = new TreeNode(2);
        for (int i = 0; i < 3; i++)
        {
            std::cout << inorderTraversal(root)[i];
        }
    }
};
