#pragma once

/*
名称：排列硬币

描述：你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。
      给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。

解题思路：1.迭代
         2.二分法
*/

#include<iostream>

class LeetCode0441 {
public:
    //二分法
    int arrangeCoins1(int n) {
        int left = 1;
        int right = n;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            long long coins = (long long)mid * (mid + 1) / 2;
            //找到完整阶梯
            if (coins == n)
            {
                return mid;
            }
            //行数不够，搜索右半部分
            else if (coins < n)
            {
                left = mid + 1;
            }//行数过多，搜索左半部分
            else
            {
                right = mid - 1;
            }
        }
        //有边界为最大完整阶梯行
        return right;
    }

    //迭代
    int arrangeCoins2(int n) {
        //最大完整阶梯行
        int result = 0;
        //当前阶梯格子数
        int i = 1;
        while (n >= 0)
        {
            n -= i;
            result++;
            i++;
        }
        return result - 1;
    }


    void test()
    {
        std::cout<<arrangeCoins2(5);
    }
};