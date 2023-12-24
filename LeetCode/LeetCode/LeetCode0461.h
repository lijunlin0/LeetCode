#pragma once

/*
名称：汉明距离

描述：两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
     给你两个整数 x 和 y，计算并返回它们之间的汉明距离。

解题思路：先将x和y进行异或操作计算出x和y不同的位置，现在不同的位置全是1，
         然后用异或的结果s和s-1进行与操作统计1的个数便是答案。
*/

#include<iostream>

class LeetCode0461 {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y;
        int result = 0;
        while (s)
        {
            s &= s - 1;
            result++;
        }
        return result;
    }

    void test()
    {
        std::cout << hammingDistance(1, 4);
    }
};