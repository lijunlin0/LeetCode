#pragma once

/*
名称：字符串中的第一个唯一字符

描述：给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。

解题思路：计数法：创建一个26大小的数组对应26个小写字母，第一遍将对应位置+1；第2遍找到第一个-1后为1的位置
*/

#include<iostream>
#include<map>
class LeetCode0387 {
public:
    int firstUniqChar(std::string s) {
        int m[26] = { 0 };
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
    void test()
    {
        std::cout<<firstUniqChar("leetcode");
    }
    
};