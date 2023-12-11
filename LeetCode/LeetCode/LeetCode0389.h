#pragma once

/*
名称：找不同

描述：给定两个字符串 s 和 t ，它们只包含小写字母。字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。请找出在 t 中被添加的字母。

解题思路：计数法：创建一个26大小的数组对应26个小写字母，第一遍将对应位置+1；第2遍找到第一个-1后为-1的位置
*/

#include<iostream>

class LeetCode0389 {
public:
    //计数法
    char findTheDifference1(std::string s, std::string t) {
        int alphabet[26] = { 0 };
        for (char c : s)
        {
            alphabet[c - 'a']++;
        }
        for (char c : t)
        {
            if (alphabet[c - 'a'] - 1 == -1)
            {
                return c;
            }
            else
            {
                alphabet[c - 'a']--;
            }
        }
        return ' ';
    }
    //位运算
    char findTheDifference2(std::string s, std::string t) {
        int ret = 0;
        for (char c : s)
        {
            ret ^= c;
        }
        for (char c : t)
        {
            ret ^= c;
        }
        return ret;
    }

    void test()
    {
        std::cout<<findTheDifference2("abcd", "abfcd");
    }
};