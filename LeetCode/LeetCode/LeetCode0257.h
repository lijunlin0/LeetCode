#pragma once
/*
���ƣ�������������·��

����������һ���������ĸ��ڵ� root ���� ����˳�� ���������дӸ��ڵ㵽Ҷ�ӽڵ��·����Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣

����˼·���õݹ�ķ�������ͣ��root->valתΪ�ַ��������ַ���path�У����ҵ�Ҷ�ӽڵ�ʱ���䴫��vector�С�
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
    //�ݹ飬�������
    void help(std::vector<std::string>& s, std::string path, TreeNode* root)
    {
        //�ս��
        if (root == nullptr)
        {
            return;
        }
        path += std::to_string(root->val);
        //�ҵ�Ҷ�ӽڵ�
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