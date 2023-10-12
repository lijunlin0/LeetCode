#pragma once
/*
名称：Excel表列名称

描述：给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
例如：
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

解题思路：实际是一道十进制转换26进制的题目，但是区间是[1,26]，所以应该先进行减一。

*/

#include<iostream>

class LeetCode0168 {
public:
    std::string convertToTitle(int columnNumber) {
        std::string str;
        while (columnNumber > 0)
        {
            columnNumber--;
            str += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        //字符反转
        reverse(str.begin(), str.end());
        return str;
    }

    void test()
    {
        std::cout<<convertToTitle(731);
    }
};
