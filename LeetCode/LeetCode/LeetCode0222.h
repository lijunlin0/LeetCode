#pragma once

/*
���ƣ���ȫ�������Ľڵ����

����������һ�� ��ȫ������ �ĸ��ڵ� root ����������Ľڵ������
     ��ȫ������ �Ķ������£�����ȫ�������У�������ײ�ڵ����û�����⣬����ÿ��ڵ������ﵽ���ֵ��
     ����������һ��Ľڵ㶼�����ڸò�����ߵ�����λ�á�����ײ�Ϊ�� h �㣬��ò���� 1~ 2h ���ڵ㡣

����˼·��
������ȫ���������ԣ�left == right����˵����������һ����������������Ϊ�ڵ��Ѿ���䵽�������ˣ��������ض��Ѿ������ˡ�
                  �����������Ľڵ��������ǿ���ֱ�ӵõ����� 2^left - 1�����ϵ�ǰ��� root �ڵ㣬�������� 2^left���ٶ����������еݹ���ҡ�

                  left != right��˵����ʱ���һ�㲻�����������ڶ����Ѿ����ˣ�����ֱ�ӵõ��������Ľڵ������
                  ͬ���������ڵ� +root �ڵ㣬����Ϊ 2^right���ٶ����������еݹ���ҡ�

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

class LeetCode0222 {
public:
    //��ȡ���
    int height(TreeNode* root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    //������ȫ����������+λ����
    int countNodes1(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        int l_height = height(root->left);
        int r_height = height(root->right);
        //���������߶���ͬ---�Ѿ���䵽��������������Ϊ������������������ȷ�������ݹ�
        if (l_height == r_height)
        {
            return (1 << l_height) + countNodes1(root->right);
        }
        //���������߶Ȳ�ͬ---��δ��䵽��������������Ϊ������������������ȷ�������ݹ�
        else
        {
            return (1 << r_height) + countNodes1(root->left);
        }
    }

    //�ݹ�
    int countNodes2(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        return countNodes2(root->left) + countNodes2(root->right) + 1;
    }

    void test()
    {
        TreeNode* head=new TreeNode(1);
        head->left = new TreeNode(2);
        head->right = new TreeNode(3);
        head->left->left = new TreeNode(4);
        head->left->right = new TreeNode(5);
        head->right->left = new TreeNode(6);
        std::cout << countNodes1(head);

    }
};