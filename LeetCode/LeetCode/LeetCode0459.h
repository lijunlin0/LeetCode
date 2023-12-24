#pragma once

/*
名称：重复的子字符串

描述：给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

解题思路：如果字符串 S 包含一个重复的子字符串，那么这意味着您可以多次 “移位和换行”`您的字符串，并使其与原始字符串匹配。
         为了提高效率，可以创建一个新的字符串 str，它等于原来的字符串 S 再加上 S 自身，这样其实就包含了所有移动的字符串。
         所以可以直接判断 str 中去除首尾元素之后，是否包含自身元素。如果包含。则表明存在重复子串。
*/

#include<iostream>

class LeetCode0459 {
public:
    bool repeatedSubstringPattern(std::string s) {
        std::string str = s + s;
        return str.substr(1, str.size() - 2).find(s) == -1 ? false : true;
    }

    void test()
    {
        std::cout << (repeatedSubstringPattern("abc") ? "true" : "false");
    }
};