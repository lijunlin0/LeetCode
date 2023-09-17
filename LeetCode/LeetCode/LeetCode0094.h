#pragma once
/*
���ƣ����������������

������
����һ���������ĸ��ڵ� root ������ ���� ���� ���� ��

����˼·���ݹ顣
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
    //�ݹ鱣������
    void inorder(TreeNode* root, std::vector<int>& nums) 
    {
        //�ս���˳�
        if (!root)
        {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    //��������
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
