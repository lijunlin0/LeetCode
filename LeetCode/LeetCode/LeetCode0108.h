#pragma once

/*
���ƣ�����������ת��Ϊ����������

����������һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ�� �߶�ƽ�� ������������
�߶�ƽ�� ��������һ�����㡸ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ���Ķ�������

����˼·�����ֲ��ҵݹ顣
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
	//�ݹ麯��
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