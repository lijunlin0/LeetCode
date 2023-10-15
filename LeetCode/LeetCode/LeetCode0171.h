#pragma once
/*
名称：Excel 表列序号

描述：给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回 该列名称对应的列序号 。

解题思路：本质是一道26进制转换10进制的题，从后向前遍历，将算出的数乘以相应位数。
*/

#include<iostream>

class LeetCode0171 {
public:
    int titleToNumber(std::string columnTitle) {
        int num = 0;
        //记录位数
        long temp = 1;
        for (int i = columnTitle.length() - 1; i >= 0; i--)
        {
            //当前位的数字
            int k = columnTitle[i] - 'A' + 1;
            //将当前位的数字乘相应的位数再加上之前的值
            num += k * temp;
            //进位
            temp *= 26;
        }
        return num;
    }


    void test()
    {
        std::cout << titleToNumber("ABC");
    }
};
