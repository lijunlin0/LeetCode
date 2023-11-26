#pragma once

/*
名称：3 的幂

描述：给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false ，
      整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x。

解题思路：方法一：3的幂n和是最大公约数必然存在倍数关系(此方法只能用于质数)。
         方法二：将 n 对 3 进行试除，直到 n 不再与 3 呈倍数关系，最后判断 n==1 即可。

*/

#include<iostream>

class LeetCode0326 {
public:
    //最大公约数
    bool isPowerOfThree1(int n) 
    {
        return n > 0 && 1162261467 % n == 0;
    }
    //试除法
    bool isPowerOfThree2(int n) {
        while (n && n % 3 == 0) 
        {
            n /= 3;
        }
        return n == 1;
    }

    void test()
    {
        std::cout << (isPowerOfThree1(27) ? "true" : "false");
    }
};