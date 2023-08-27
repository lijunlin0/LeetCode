#pragma once
/*
名称：最长公共前缀

描述：
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

解题思路：用两层循环实现，第一层循环遍历字符，第二层循环遍历每个字符串，若发现某一字符串找完则返回到当前下标前一个的字符串，若发现某一字符和共同前缀不同则返回到当前下标前一个的字符串。
substr(i,j)：返回从i下标开始的j个字符。
*/
#include<vector>
#include<iostream>
using namespace std;

class LeetCode0014
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int i = 0;
        while (true)
        {
            for (int j = 0; j < strs.size(); j++)
            {
                //最短字符串出现，结束
                if (i >= strs[j].size())
                {
                    return strs[j].substr(0, i);
                }
                //第一个不相同的字符串，结束
                if (strs[j][i] != strs[0][i])
                {
                    return strs[j].substr(0, i);
                }
            }
            i++;
        }
        //全部字符串相同，返回第一个
        return strs[0];
    }
    void test()
    {
        vector<string> strs;
        strs.push_back("flower");
        strs.push_back("flower");
        strs.push_back("flower");
        cout<<longestCommonPrefix(strs);
    }
};