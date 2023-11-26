#pragma once

/*
名称：反转字符串中的元音字母

描述：给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
      元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。

      
解题思路：双指针指向首尾，先让两个指针分别指向第一个元音字母，然后和进行交换。
*/

#include<vector>
#include<iostream>

class LeetCode0345 {
public:
    std::string reverseVowels(std::string s) 
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            //分别找到第一个元音字母
            while (i < s.size() - 1 && s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
            {
                i++;
            }
            while (j > 0 && s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U')
            {
                j--;
            }
            if (i < j)
            {
                std::swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }

    void test()
    {
        std::cout << reverseVowels("hello");
    }

};