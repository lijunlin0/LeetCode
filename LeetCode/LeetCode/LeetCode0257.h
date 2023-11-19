#pragma once
/*
名称：二叉树的所有路径

描述：给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。叶子节点 是指没有子节点的节点。

解题思路：用递归的方法，不停将root->val转为字符串存入字符串path中，在找到叶子节点时将其传入vector中。
*/

#include<iostream>
#include<vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class LeetCode0257 {
public:
    //递归，深度优先
    void help(std::vector<std::string>& s, std::string path, TreeNode* root)
    {
        //空结点
        if (root == nullptr)
        {
            return;
        }
        path += std::to_string(root->val);
        //找到叶子节点
        if (!root->left && !root->right)
        {
            s.push_back(path);
            return;
        }
        path += "->";
        help(s, path, root->left);
        help(s, path, root->right);
    }
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> s;
        help(s, "", root);
        return s;
    }

    void test()
    {
        TreeNode* head = new TreeNode(1);
        head->left = new TreeNode(2);
        head->right = new TreeNode(3);
        head->left->right = new TreeNode(5);
        std::vector<std::string> s = binaryTreePaths(head);
        for (int i = 0; i < s.size(); i++)
        {
            std::cout << s[i] << ',';
        }
    }
};