#pragma once
#include<iostream>
#include<math.h>

/*
���ƣ�ƽ�������

���ƣ�����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
�����У�һ�ø߶�ƽ�����������Ϊ��һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��

����˼·����һ���ݹ麯���������ڵ�ĸ߶ȣ�Ȼ����ԭ�����еݹ��ж�ÿһ�ڵ�ĸ߶Ȳ�
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
    //�ݹ麯������ڵ�ĸ߶�
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
        //ÿһ���ڵ�ĸ߶Ȳ�С�ڵ���1�����򷵻�false
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