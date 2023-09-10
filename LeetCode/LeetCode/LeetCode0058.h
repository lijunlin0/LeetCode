#pragma once
/*
名称：最后一个单词的长度

描述：给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

解题思路：反向遍历，先用一个循环将i跳过空格，然后通过i遍历字母，遍历到的每个字母数则是单词的长度，直到找到一个空格为止。
*/
#include<iostream>
using namespace std;

class LeetCode0058
{
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int num = 0;
        //跳过结尾空格
        while (s[i] == ' ')
        {
            i--;
        }
        while (i >= 0 && s[i] != ' ')
        {
            num++;
            i--;
        }
        return num;
    }
    void test()
    {
        string s = " fly to  the  moon   ";
        cout << lengthOfLastWord(s);
    }
};