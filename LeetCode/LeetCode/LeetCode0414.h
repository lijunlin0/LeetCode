#pragma once

/*
名称：第三大的数

描述：给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。

解题思路：定义三个变量分别表示前三大小的数字，遍历数组改变其大小，当较大值改变时，较小时应继承之前的较大值。
*/

#include<iostream>
#include<vector>

class LeetCode0414 {
public:
    int thirdMax(std::vector<int>& nums) {
        long one = LONG_MIN;
        long two = LONG_MIN;
        long res = LONG_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            //比最大值大
            if (nums[i] > one)
            {
                res = two;
                two = one;
                one = nums[i];
            }
            //比第二大值大
            else if (one > nums[i] && nums[i] > two)
            {
                res = two;
                two = nums[i];
            }
            //比第三大值大
            else if (two > nums[i] && nums[i] > res)
            {
                res = nums[i];
            }
        }
        return res == LONG_MIN ? one : res;
    }

    void test()
    {
        std::cout << thirdMax(std::vector<int>()={2,2,3,1});
    }
};