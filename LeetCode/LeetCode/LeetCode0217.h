#pragma once

/*
名称：存在重复元素

描述：给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。

解题思路：遍历数组，同时查询无序容器中是否有此数，若有则直接返回true，反之则添加到容器中，遍历完后返回false。
*/

#include<iostream>
#include<vector>
#include<unordered_set>

class LeetCode0217
{
public:
	bool containsDuplicate(std::vector<int>& nums) {
		std::unordered_set<int> uset;
		for (int i = 0; i < nums.size(); i++)
		{
			//若找到重复数
			if (uset.count(nums[i]))
			{
				return true;
			}
			else
			{
				uset.insert(nums[i]);
			}
		}
		return false;
	}

	void test()
	{
		std::vector<int> nums = { 1,1,1,3,3,4,3,2,4,2 };
		std::cout << containsDuplicate(nums);
	}
};
