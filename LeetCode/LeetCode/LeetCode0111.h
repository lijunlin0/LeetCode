#pragma once
#include<iostream>

/*

���ƣ�����������С���

����������һ�����������ҳ�����С��ȡ���С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

����˼·�����������Ȳ�ͬ�㣺�����Ӻ��Һ��Ӷ�û�нڵ�ʱ������ȣ�Ȼ��ݹ������С���
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