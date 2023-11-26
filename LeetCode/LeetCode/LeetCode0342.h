#pragma once

/*
名称：4的幂

描述：给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。
      整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x

解题思路：判断是否是2的幂次方并且取模于3等于1。
*/

#include<iostream>

class LeetCode0342 {
public:
    //取模性质
    bool isPowerOfFour1(int n) 
    {
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }

    //试除法
    bool isPowerOfFour2(int n) 
    {
        while (n && n % 4 == 0)
        {
            n /= 4;
        }
        return n == 1;
    }

    void test()
    {
        std::cout << (isPowerOfFour1(16) ? "true" : "false");
    }
};