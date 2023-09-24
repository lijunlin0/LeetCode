#include<iostream>

/*
名称：验证回文串

描述：如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
字母和数字都属于字母数字字符。
给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

解题思路：双指针，边操作边判断
*/

#pragma once
class LeetCode0125 {
public:
    bool isPalindrome(std::string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            //如果为非字母数字字符则i++
            while (i < j && !isalnum(s[i]))
            {
                i++;
            }
            //如果为非字母数字字符则j++
            while (i < j && !isalnum(s[j]))
            {
                j--;
            }
            //如果小写后的字符不相等则直接返回false
            if (tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
            i++;
            j--;
        }
        //最后返回true
        return true;
    }
    void test()
    {
        std::string s = { "A man, a plan, a canal: Panama" };
        std::cout<<isPalindrome(s);
    }
};