#pragma once

/*
名称：字符串中的单词数

描述：统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
     请注意，你可以假定字符串里不包括任何不可打印的字符。

解题思路：遍历字符串，统计每个单词的第一个下标的数量。
*/

#include<iostream>

class LeetCode0434 {
public:
    int countSegments(std::string s) {
        int segmentCount = 0;

        for (int i = 0; i < s.size(); i++) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                segmentCount++;
            }
        }

        return segmentCount;
    }

    void test()
    {
        std::cout<<countSegments(", , , ,        a, eaefa");
    }
};