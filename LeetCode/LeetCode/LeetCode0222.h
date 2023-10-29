#pragma once

/*
名称：完全二叉树的节点个数

描述：给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
     完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
     并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

解题思路：
利用完全二叉树特性：left == right。这说明，左子树一定是满二叉树，因为节点已经填充到右子树了，左子树必定已经填满了。
                  所以左子树的节点总数我们可以直接得到，是 2^left - 1，加上当前这个 root 节点，则正好是 2^left。再对右子树进行递归查找。

                  left != right。说明此时最后一层不满，但倒数第二层已经满了，可以直接得到右子树的节点个数。
                  同理，右子树节点 +root 节点，总数为 2^right。再对左子树进行递归查找。

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
    //获取深度
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
    //利用完全二叉树特性+位运算
    int countNodes1(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        int l_height = height(root->left);
        int r_height = height(root->right);
        //左右子树高度相同---已经填充到右子树，左子树为满二叉树，右子树不确定继续递归
        if (l_height == r_height)
        {
            return (1 << l_height) + countNodes1(root->right);
        }
        //左右子树高度不同---还未填充到右子树，右子树为满二叉树，左子树不确定继续递归
        else
        {
            return (1 << r_height) + countNodes1(root->left);
        }
    }

    //递归
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