#pragma once

/*
名称：字符串转换整数 (atoi)

描述：请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。
     函数 myAtoi(string s) 的算法如下：

     1.读入字符串并丢弃无用的前导空格
     2.检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
     3.读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
     4.将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
     5.如果整数数超过 32 位有符号整数范围 [INT_MIN,  INT_MAX] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 INT_MIN 的整数应该被固定为 INT_MIN ，大于 INT_MAX 的整数应该被固定为 INT_MAX 。
     6.返回整数作为最终结果。
注意：
本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。

描述：1.先跳过前导空格 2.判断正负 3.字符转换为数字并判断是否溢出
*/

#include<iostream>
#include <string>

class LeetCode0008 {
public:
    int myAtoi(std::string s) {
        int i = 0;
        //跳过前导空格
        while (s[i] == ' ')
        {
            i++;
        }
        //判断正负
        int is_minus = 1;
        if (s[i] == '-' || s[i] == '+')
        {
            is_minus = s[i++] == '-' ? -1 : 1;

        }
        //char转换int
        int result = 0;
        while ((int)s[i] >= '0' && (int)s[i] <= '9' && i < s.size())
        {
            int digit = s[i++] - '0';
            //判断越界
            if (result > ((INT_MAX - digit) / 10))
            {
                //根据正负判断返回值
                return is_minus == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
        }
        return result * is_minus;
    }

    void test()
    {
        std::string s = "4193 with words";
        std::cout << myAtoi(s);
    }
};