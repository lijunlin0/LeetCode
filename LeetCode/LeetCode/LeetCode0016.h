#pragma once

/*
名称：最接近的三数之和

描述：给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，
     使它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在恰好一个解。

解题思路：1.对数组进行排序。
         2.遍历数组：
         (1)若 sum==target：直接返回sum;
         (2)若sum<target:再判断与target的距离是否更小，若更小则更新并跳过重复元素;
         (3)若sum>target:再判断与target的距离是否更小，若更小则更新并跳过重复元素;
         3.若循环完没有返回则表示没有三个数的和等于target则返回target+距离(gap);
*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class LeetCode0016 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int gap = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int L = i + 1;
            int R = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            while (L < R)
            {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == target)
                {
                    return sum;
                }
                if (sum < target)
                {
                    if (abs(sum - target) < abs(gap))
                    {
                        gap = -abs(sum - target);
                    }
                    while (L < R && nums[L] == nums[L + 1])
                    {
                        L++;
                    }
                    L++;
                }
                else
                {
                    if (abs(sum - target) < abs(gap))
                    {
                        gap = abs(sum - target);
                    }
                    while (L < R && nums[R] == nums[R - 1])
                    {
                        R--;
                    }
                    R--;
                }
            }
        }
        return target + gap;
    }

    void test()
    {
        std::cout<<threeSumClosest(std::vector<int>() = { 2,3,8,9,10 }, 16);
    }
};
