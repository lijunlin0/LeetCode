#pragma once
/*
����:��������ǰ�����

����������������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������

����˼·������һ����������vector�洢�ݹ������ֵ
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
    //�ݹ麯��
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
        //���ڴ洢����ֵ
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