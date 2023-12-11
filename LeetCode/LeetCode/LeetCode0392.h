#pragma once

/*
名称：判断子序列

描述：给定字符串 s 和 t ，判断 s 是否为 t 的子序列。字符串的一个子序列是原始字符串删除一些（也可以不删除）
     字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

解题思路：双指针i,j指向字符串s,t的首部，j不断向前寻找，当两下标位置元素相同时i前进一次。循环结束时判断i是否等于s的大小。
*/

#include<iostream>

class LeetCode0392 {
public:
    //双指针
    bool isSubsequence(std:: string s, std::string t) {
        int i = 0;
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i] == t[j])
            {
                i++;
            }
        }
        return i == s.size();
    }

    void test()
    {
        std::cout << (isSubsequence("abc", "ahgbsc")?"true" : "false");
    }
};