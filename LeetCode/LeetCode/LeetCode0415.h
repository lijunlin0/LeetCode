#pragma once

/*
名称：字符串相加

描述：给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
     你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

解题思路：从后往前遍历两个字符串，将其相加，并记录进位值。有字符串计算完时在相应位置补0，若进位值不为0则需将进位值加上。     
*/

#include<iostream>
#include<string>

class LeetCode0415 {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int count = 0;
        std::string res = "";
        for (int i = num1.size() - 1, j = num2.size() - 1; j >= 0 || i >= 0; i--, j--)
        {
            //若计算完则补0
            int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
            int digit2 = (j >= 0) ? (num2[j] - '0') : 0;
            
            //两数之和加进位值
            int sum = digit1 + digit2 + count;
            count = 0;
            //需要进位
            if (sum >= 10)
            {
                count = 1;
                sum -= 10;
            }
            res += std::to_string(sum);
        }
        //最后进位值不为0需加上进位值
        if (count != 0)
        {
            res += std::to_string(count);
        }
        //反转字符串
        reverse(res.begin(), res.end());
        return res;
    }

    void test()
    {
        std::cout << addStrings("456", "77");
    }
};