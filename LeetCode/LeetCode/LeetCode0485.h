#pragma once

/*
名称：最大连续 1 的个数

描述：给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。

解题思路：迭代
*/

#include<iostream>
#include<vector>

class LeetCode0485 {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int temp = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                temp++;
            }
            else
            {
                res = std::max(temp, res);
                temp = 0;
            }
        }
        //结尾判断一次
        return std::max(temp, res);;
    }

    void test()
    {
        std::cout << findMaxConsecutiveOnes(std::vector<int>() = { 1,1,0,1,1,1 });
    }
};
