#pragma once

/*
名称：相同的树

描述：
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

解题思路：递归查询两个节点的左值和右值是否相同。
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
        //如果发现值不同，则不同
        else if (p->val != q->val)
        {
            return false;
        }
        else
        {
            //递归查询p左q左 和 p右q右
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
