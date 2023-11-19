#pragma once

/*
名称：单词规律

描述：给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。

解题思路:创建一个map通过映射来判断是否符合规律
*/

#include<unordered_map>
#include<iostream>]

class LeetCode0290 {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::unordered_map<std::string, char> ps;
        int first = 0;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i+1] == ' '||i+1==s.size())
            {
                std::string str = s.substr(first, i+1 - first);
                first = i + 2;
                //是否找到
                bool find = false;
                for (std::unordered_map<std::string, char>::iterator it = ps.begin(); it != ps.end(); it++)
                {
                    if (it->second==pattern[j])
                    {
                        if (it->first == str)
                        {
                            find = true;
                        }
                        //是否匹配
                        else
                        {
                            return false;
                        }
                    }
                    //是否匹配
                    else if (it->first == str&&it->second!=pattern[j])
                    {
                        return false;
                    }
                }
                //未找到
                if (!ps.count(str) && !find)
                {
                    ps[str] = pattern[j];
                }
                j++;
            }
        }
        //是否遍历完规律字符串
        return j==pattern.size();
    }

    void test()
    {
        std::string pattern = "abba";
        std::string s = "dog cat cat dog";
        std::cout<<(wordPattern(pattern, s)?"true":"false");
    }
};
