#pragma once

/*
名称：x 的平方根

描述：
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

解题思路：二分查找法
*/

#include<iostream>

class LeetCode0069
{
public:
    int mySqrt(int x) {
        int i = 1;
        int j = x;
        int ans = 0;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (mid > x / mid)
            {
                j = mid - 1;
            }
            else
            {
                ans = mid;
                i = mid + 1;
            }
        }
        return ans;
    }
    void test()
    {
        std::cout<<mySqrt(900);
    }
};
