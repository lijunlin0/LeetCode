#pragma once

/*
���ƣ������ظ�Ԫ��

����������һ���������� nums �������һֵ�������г��� �������� ������ true �����������ÿ��Ԫ�ػ�����ͬ������ false ��

����˼·���������飬ͬʱ��ѯ�����������Ƿ��д�����������ֱ�ӷ���true����֮����ӵ������У�������󷵻�false��
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
			//���ҵ��ظ���
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
