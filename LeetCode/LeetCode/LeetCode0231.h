#pragma once

/*
名称：2 的幂

描述：给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
     如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

解题思路：若n=2的x次方，恒有 n & (n - 1) == 0，这是因为：
         n 二进制最高位为 1，其余所有位为 0；
         n−1 二进制最高位为 0，其余所有位为 1；
         一定满足 n > 0。
*/

#include<iostream>
#include<math.h>
class LeetCode0231 {
public:
    //利用二进制性质
    bool isPowerOfTwo1(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    //右移
    bool isPowerOfTwo2(int n) {
        if (!n)
        {
            return false;
        }
        while (n % 2 == 0)
        {
            n >>= 1;
        }
        return n == 1;
    }
    void test()
    {
        std::cout << isPowerOfTwo1(16);
    }
};