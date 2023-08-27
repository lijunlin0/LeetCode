#pragma once
/*
名称：搜索插入位置

描述：给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。---（请必须使用时间复杂度为 O(log n) 的算法。）

解题思路：
二分查找：声明l为数组首部，r为数组尾部，每次查找定义一个mid位于数组中间，然后根据目标值和mid下标值比较进行l和r的更新。
*/
#include<iostream>
#include<vector>
using namespace std;

class LeetCode0035
{
public:
    //二分查找
    int searchInsert1(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
    //遍历（不符合题目要求）
	int searchInsert2(vector<int>& nums, int target)
	{
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums[i] >= target)
			{
				return i;
			}
		}
		return n;
	}
    
	void test()
	{
		vector<int>nums = {1};
		cout << searchInsert1(nums, 2);
	}
};
