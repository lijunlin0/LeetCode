#pragma once

/*
���ƣ���ͬ����

������
�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

����˼·���ݹ��ѯ�����ڵ����ֵ����ֵ�Ƿ���ͬ��
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

class LeetCode0100 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }
        //�������ֵ��ͬ����ͬ
        else if (p->val != q->val)
        {
            return false;
        }
        else
        {
            //�ݹ��ѯp��q�� �� p��q��
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }

    void test()
    {
        TreeNode* p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(3);

        TreeNode* q = new TreeNode(1);
        q->left = new TreeNode(2);
        q->right = new TreeNode(3);
        std::cout << isSameTree(p, q);
    }
};
