#pragma once

/*
名称：数字转换为十六进制数

描述：给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。

注意:
十六进制中所有字母(a-f)都必须是小写。
十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。
给定的数确保在32位有符号整数范围内。
不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法

解题思路：将负整型转换为无符号整型就是进行补码运算
*/

#include<iostream>

class LeetCode0405 {
public:
    std::string toHex(int num) {
        std::string s = "";
        if (num == 0)
        {
            return "0";
        }
        //转换为无符号整型就是补码运算
        unsigned int uNum = static_cast<unsigned int>(num);  // 转为无符号整数
        while (uNum > 0)
        {
            long temp = uNum % 16;
            uNum /= 16;
            s += to_16(temp);
        }
        //反转
        std::reverse(s.begin(), s.end());
        return s;
    }

    char to_16(int num)
    {
        switch (num)
        {
        case 0:return '0'; break;
        case 1:return '1'; break;
        case 2:return '2'; break;
        case 3:return '3'; break;
        case 4:return '4'; break;
        case 5:return '5'; break;
        case 6:return '6'; break;
        case 7:return '7'; break;
        case 8:return '8'; break;
        case 9:return '9'; break;
        case 10:return 'a'; break;
        case 11:return 'b'; break;
        case 12:return 'c'; break;
        case 13:return 'd'; break;
        case 14:return 'e'; break;
        case 15:return 'f'; break;
        default:return ' ';
        }
    }

    void test()
    {
        std::cout << toHex(-1);
    }
};