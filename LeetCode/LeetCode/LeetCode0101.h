#pragma once

/*
名称：对称二叉树

描述：给你一个二叉树的根节点 root ， 检查它是否轴对称。

解题思路：将树分为两部分，根的左节点和右节点，
然后递归查询 左节点的左节点 和 右节点的右节点 是否相同 并且查询 左节点的右节点 和 右节点的左节点 是否相同。
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

class LeetCode0101 {
public:
    bool isSymmetricNode(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }
        else if (p->val != q->val)
        {
            return false;
        }
        else
        {
            return isSymmetricNode(p->left, q->right) && isSymmetricNode(p->right, q->left);
        }
    }

    bool isSymmetric(TreeNode* root) {
        return isSymmetricNode(root->left, root->right);
    }

    void test()
    {
        TreeNode* root = new TreeNode(0);
        root->left = new TreeNode(1);
        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(3);
        root->right = new TreeNode(1);
        root->right->left = new TreeNode(3);
        root->right->right = new TreeNode(2);

        std::cout << isSymmetric(root);
    }
};