#pragma once

/*
���ƣ��Գƶ�����

����������һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�

����˼·��������Ϊ�����֣�������ڵ���ҽڵ㣬
Ȼ��ݹ��ѯ ��ڵ����ڵ� �� �ҽڵ���ҽڵ� �Ƿ���ͬ ���Ҳ�ѯ ��ڵ���ҽڵ� �� �ҽڵ����ڵ� �Ƿ���ͬ��
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