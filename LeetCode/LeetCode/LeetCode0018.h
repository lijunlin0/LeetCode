#pragma once

/*
解题思路：四数之和

描述：给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

解题思路：1.特殊判断，对于数组长度 n，如果数组长度小于 34，直接返回。
         2.对数组进行排序。
         3.遍历数组：
         第一个位置：
         (1) 跳过重复解
         (2) 去枝操作
         第二个位置：
         (1) 跳过重复解
         (2) 去枝操作
         (3) 令左指针 L=i+1，右指针 R=n−1，当 L<R时，执行循环：
             当 nums[i]+nums[j]+nums[L]+nums[R]==target，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,R 移到下一位置，寻找新的解
             若和大于 0，说明 nums[R] 太大，R 左移使其变小
             若和小于 0，说明 nums[L] 太小，L 右移使其变大
*/

#include<iostream>
#include<vector>
#include <queue>

class LeetCode0018 {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        int length = nums.size();
        if (length < 4)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length - 3; i++)
        {
            //跳过重复数
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            //剪枝操作
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if ((long)nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++)
            {
                //跳过重复数
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                //剪枝操作
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if ((long)nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;
                }

                int L = j + 1;
                int R = length - 1;
                while (L < R)
                {
                    long sum = (long)nums[i] + nums[j] + nums[L] + nums[R];
                    if (sum == target)
                    {
                        res.push_back(std::vector<int >() = { nums[i],nums[j], nums[L], nums[R] });
                        //去除重复解
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
                    else if (sum < target)
                    {
                        L++;
                    }
                    else
                    {
                        R--;
                    }
                }
            }
        }
        return res;
    }

    void test()
    {
        std::vector<int> temp = { 1,0,-1,0,-2,2 };
        std::vector<std::vector<int>> result = fourSum(temp,0);
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