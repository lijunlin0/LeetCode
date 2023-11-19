#pragma once

/*
名称：无重复字符的最长子串

描述：给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

解题思路：滑动窗口：遍历一次字符串，left为窗口左侧；
                  1.找到重复字符---循环删除到重复值处
                  2.未找到时---添加值到set并改变最大值
*/

#include<iostream>
#include<unordered_set>

class LeetCode0003 {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() == 0)
        {
            return 0;
        }
        std::unordered_set<char> set;
        //最大值
        int max_str = 0;
        //窗口左侧
        int left = 0;
        //遍历字符串
        for (int i = 0; i < s.size(); i++)
        {
            //找到重复字符---循环删除到重复值处
            while (set.find(s[i]) != set.end())
            {
                set.erase(s[left]);
                left++;
            }
            //未找到时---添加值到set并改变最大值
            max_str = std::max(max_str, i - left + 1);
            set.emplace(s[i]);
        }
        return max_str;
    }

    void test()
    {
        std::string s = "abcabcbb";
        std::cout << lengthOfLongestSubstring(s);
    }
};