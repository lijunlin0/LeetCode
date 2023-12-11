#pragma once

/*
名称：三数之和

描述：给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
     你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

解题思路：1.特殊判断，对于数组长度 n，如果数组长度小于 3，直接返回。
         2.对数组进行排序。
         3.遍历数组：
         (1)若 nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果。
         (2) 对于重复元素：跳过，避免出现重复解
         (3) 令左指针 L=i+1，右指针 R=n−1，当 L<R时，执行循环：
             当 nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,R 移到下一位置，寻找新的解
             若和大于 0，说明 nums[R] 太大，R 左移使其变小
             若和小于 0，说明 nums[L] 太小，L 右移使其变大

*/

#include<iostream>
#include<vector>
#include <algorithm>

class LeetCode0015 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector < std::vector<int>> res;
        if (nums.size() < 3)
        {
            return res;
        }
        //排序
        std::sort(nums.begin(), nums.end());
        //遍历数组
        for (int i = 0; i < nums.size(); i++)
        {
            //特殊判断
            if (nums[i] > 0)
            {
                break;
            }
            //跳过重复数
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            //左右指针
            int L = i + 1;
            int R = nums.size() - 1;
            while (L < R)
            {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0)
                {
                    res.push_back(std::vector<int >() = { nums[i], nums[L], nums[R] });
                    //跳过重复数
                    while (L < R && nums[L] == nums[L + 1])
                    {
                        L++;
                    }
                    while (L < R && nums[R] == nums[R - 1])
                    {
                        R--;
                    }
                    L++;
                    R--;
                }
                //使其变大
                else if (sum < 0)
                {
                    L++;
                }
                //使其变小
                else
                {
                    R--;
                }
            }
        }
        return res;
    }

    void test()
    {
        std::vector<int> temp = { -1, 0, 1, 2, -1, -4 };
        std::vector<std::vector<int>> result=threeSum(temp);
        for (int i = 0; i < result.size(); i++)
        {
            std::cout << '[';
            for (int j = 0; j < result[i].size(); j++)
            {
                std::cout << result[i][j] << ',';
            }
            std::cout << "],";
        }
    }
};