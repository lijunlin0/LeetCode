#pragma once

/*
名称：各位相加

描述：给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。

解题思路：双层循环，每次取下最后一位数进行累加。
*/

#include<iostream>

class LeetCode0258 {
public:
    int addDigits(int num) {
        while (num >= 10)
        {
            int sum = 0;
            while (num)
            {
                sum += num % 10;;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }

    void test()
    {
        std::cout<<addDigits(567);
    }
};