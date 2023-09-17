
/*
名称：二叉树的最大深度

描述：
给定一个二叉树 root ，返回其最大深度。
二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

解题思路：递归比较左右节点的最大深度。
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

class LeetCode0104 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    void test()
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(3);
        root->right = new TreeNode(2);
        root->right->left = new TreeNode(4);
        std::cout << maxDepth(root);
    }
};