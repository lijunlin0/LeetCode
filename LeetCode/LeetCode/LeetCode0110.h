#pragma once
#include<iostream>
#include<math.h>

/*
名称：平衡二叉树

名称：给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

解题思路：用一个递归函数算出传入节点的高度，然后在原函数中递归判断每一节点的高度差
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class LeetCode0110 {
public:
    //递归函数算出节点的高度
    int height(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return std::max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }
        //每一个节点的高度差小于等于1，否则返回false
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    void test()
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        std:: cout << isBalanced(root);
    }
};