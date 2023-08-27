#pragma once
/*
名称：移除元素

描述：
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

解题思路：
双指针：首先将两个指针指向首部，i用于赋值，j用于查找，j不停往前进，跳过nums[j]==val的地方，直到nums[j]!=val就将其赋值给nums[i],然后i前进。
双指针优化：将i放置于数组首部，j放置于数组最后一位的后面，如果nums[i]!=val则i前进，否则则将j-1位置的元素赋值到i位置，然后j向左移。
优化后的优点：两个指针在最坏的情况下加起来只遍历了数组一次，与未优化的双指针不同的是，优化后避免了需要保留的元素的重复赋值操作。
*/
#include<iostream>
#include<vector>
using namespace std;

class LeetCode0027
{
public:
	//双指针优化
	int removeElement1(vector<int>& nums, int val)
	{
		int i = 0;
		int j = nums.size();
		while (i<j)
		{
			if (nums[i] == val)
			{
				nums[i] = nums[j-1];
				j--;
			}
			else
			{
				i++;
			}
		}
		return i;
	}
	//双指针
	int removeElement2(vector<int>& nums, int val) {
		int i = 0;
		int j = 0;
		for (; j < nums.size(); j++)
		{
			if (nums[j] != val)
			{
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
	void test()
	{
		vector<int> nums = { 3,2,2,3 };
		cout<<removeElement1(nums, 3);
	}
};
