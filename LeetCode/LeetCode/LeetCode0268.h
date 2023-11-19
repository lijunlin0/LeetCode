#pragma once

/*
名称：丢失的数字

描述：给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

解题思路：异或运算：任何数和0做异或运算，结果仍然是原来的数，即 a ^ 0 = a。
                  任何数和其自身做异或运算，结果是0，即 a ^ a = 0。
                  第一次遍历对从 0 到 n 的所有整数进行异或操作。第二次遍历对数组中的每一个数进行异或操作。
                  最终结果就是缺失的数。
*/

#include<iostream>
#include<vector>
#include <queue>

class LeetCode0268 {
public:
    //异或运算
    int missingNumber1(std::vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            ans ^= i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
    //排序
    int missingNumber2(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int a = 0; a < nums.size(); a++)
        {
            if (a != nums[a])
            {
                return a;
            }
        }
        return nums.size();
    }

    void test()
    {
        std::vector<int> nums = { 0,1,2,4,5,6,7,8,9 };
        std::cout << missingNumber1(nums);
    }
};