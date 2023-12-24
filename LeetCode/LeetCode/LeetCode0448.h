#pragma once

/*
名称：找到所有数组中消失的数字

描述：给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。

解题思路：将数组中数字存入哈希表，再遍历1到n查找。
*/

#include<iostream>
#include<vector>
#include <queue>
#include<unordered_set>

class LeetCode0448 {
public:

    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::vector<int> result;
        std::unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.emplace(nums[i]);
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            if (!s.count(i))
            {
                result.push_back(i);
            }
        }
        return result;
    }


    void test()
    {
        std::vector<int> result = findDisappearedNumbers(std::vector<int>() = { 1,2 });
        for (int i = 0; i < result.size(); i++)
        {
            std::cout << result[i] << ',';
        }
    }
};