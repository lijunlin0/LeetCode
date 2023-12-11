#pragma once

/*
名称：最长回文串

描述：给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。
     在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。

解题思路：创建一个128大小的整型数组，保证每个字母都能对应，遍历字符串s，如果遇到偶数个字母则将结果加2，最后判断结果和字符串的大小关系判断是否加1。    
*/

#include<iostream>
#include<set>

class LeetCode0409
{
public:
    int longestPalindrome(std::string s) {
        int temp[128] = { 0 };
        //结果
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            //对应字母加1
            temp[c]++;
            //遇到偶数
            if (temp[c] == 2)
            {
                ans += 2;
                temp[c] = 0;
            }
        }
        //若有剩余字母则加1
        return ans < s.size() ? ans + 1 : ans;
    }

    void test()
    {
        std::cout<<longestPalindrome("abccccdd");
    }
};