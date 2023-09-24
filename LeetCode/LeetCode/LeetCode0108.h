#pragma once

/*
名称：将有序数组转换为二叉搜索树

描述：给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

解题思路：二分查找递归。
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

class LeetCode0108
{
public:
	//递归函数
	TreeNode* sortedArrayToBST_(std::vector<int>& nums,int left,int right)
	{
		if (left> right)
		{
			return nullptr;
		}
		int mid = (left + right) / 2;

		TreeNode* root = new TreeNode();
		root->val = nums[mid];
		root->left = sortedArrayToBST_(nums, left, mid - 1);
		root->right = sortedArrayToBST_(nums, mid + 1, right);
		return root;
	}


	TreeNode* sortedArrayToBST(std::vector<int>& nums) 
	{

		return sortedArrayToBST_(nums, 0, nums.size() - 1);
	}

	void test()
	{
		std::vector<int> nums = { -10,-3,0,5,9 };
		TreeNode* t=sortedArrayToBST(nums);
		std::cout << t->val << ',' << t->left->val << ',' << t->left->right->val << ',' << t->right->val << ',' << t->right->right->val << std::endl;

	}
};