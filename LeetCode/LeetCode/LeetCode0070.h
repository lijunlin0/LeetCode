#pragma once

/*
名称：爬楼梯

描述：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

解题思路：动态规划：第 x 级台阶的方案数是爬到第 x−1 级台阶的方案数和爬到第 x−2 级台阶的方案数的和 ---f(x)=f(x-1)+f(x-2);
*/

#include<iostream>

class LeetCode0070
{
public:
    //动态规划（优解）
    int climbStairs1(int n) {
        int a = 0;
        int b = 0;
        int r = 1;
        for (int i = 1; i <= n; i++)
        {
            a = b;
            b = r;
            r = a + b;
        }
        return r;
    }
    //递归
    int climbStairs2(int n) {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        return climbStairs2(n - 1) + climbStairs2(n - 2);
    }
    void test()
    {
        std::cout << "动态规划：" << climbStairs1(5) << std::endl;
        std::cout << "递归：" << climbStairs2(5) << std::endl;

    }
};