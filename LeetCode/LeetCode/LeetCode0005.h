#pragma once

/*
名称：最长回文子串

描述：给你一个字符串 s，找到 s 中最长的回文子串。
     如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

解题思路：1.中心扩散法：遍历s的每个下标，向两边扩散找到最大回文字符串。
         2.暴力解法：挨个遍历，判断两下标内的字符串是否为最大回文字符串。
*/

#include<iostream>
#include<vector>
#include <string>

class LeetCode0005 {
public:

    //中心扩散法
    std::string longestPalindrome1(std::string s) {
        //第一个位置记录开始下标，第二个位置记录回文串长度
        std::vector<int> res = { 0,1 };
        int max_len = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            //奇数扩散数组
            std::vector<int> odd = { 0,1 };
            //偶数扩散数组
            std::vector<int> even = { 0,1 };
            center(odd, s, i, i);
            center(even, s, i, i + 1);
            //取奇偶数扩散较大的数组
            std::vector<int> max_temp = odd[1] > even[1] ? odd : even;
            if (max_temp[1] > max_len)
            {
                res = max_temp;
                max_len = max_temp[1];
            }
        }
        //裁剪出最大回文串
        return s.substr(res[0], res[1]);
    }

    //中心扩散，改变引用的数组为扩散到的最大回文串
    void center(std::vector<int>& res, std::string& s, int left, int right)
    {
        int n = s.size();
        while (left >= 0 && right < n)
        {
            if (s[left] != s[right])
            {
                break;
            }
            left--;
            right++;
        }
        //+1为上一次的位置，即为扩散到的最大回文串边界
        res[0] = left + 1;
        res[1] = right - left - 1;
    }
    
    //暴力解法
    std::string longestPalindrome2(std::string s) {
        if (s.size() == 1)
        {
            return s;
        }
        //最大回文串长度
        int max = 1;
        //最大回文串开始下标
        int begin = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if ((j - i + 1) > max && is_palindrome(i, j, s))
                {
                    max = j - i + 1;
                    begin = i;
                }
            }
        }
        //裁剪出最大回文串
        return s.substr(begin, max);
    }

    //判断两指针内的字符串是否是回文串
    bool is_palindrome(int i, int j, std::string& s)
    {
        for (; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
   



    void test()
    {
        std::cout << longestPalindrome1("cbbd");
    }
};