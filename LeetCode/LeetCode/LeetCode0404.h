#pragma once

/*
���ƣ���Ҷ��֮��

�����������������ĸ��ڵ� root ������������Ҷ��֮�͡�

����˼·���ݹ飺ֻ�е�ǰ�����Ľڵ��Ǹ��ڵ㣬�����ж����ӽڵ��ǲ�����Ҷ�ӣ��ж���ڵ���ڣ�����û�������ӽڵ��򷵻���ֵ��
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
        //��ڵ�ΪҶ�ӽڵ�
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