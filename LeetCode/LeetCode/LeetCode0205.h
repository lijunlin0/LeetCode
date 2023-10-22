#pragma once
/*
名称：同构字符串

描述：给定两个字符串 s 和 t ，判断它们是否是同构的。
如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，
相同字符只能映射到同一个字符上，字符可以映射到自己本身。

解题思路：哈希表：遍历字符串，将 s字符串 对应下标的字符与 t字符串 对应下标的字符存为一对形成映射关系，
                 然后判断字符的映射和对应下标的字符是否相同。
*/

#include<iostream>
#include<unordered_map>
class LeetCode0205 {
public:
    //哈希表直接判断
    bool isIsomorphic1(std::string s, std::string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        std::unordered_map<char, int> m1;
        std::unordered_map<char, int> m2;
        int length = s.size();
        for (int i = 0; i < length; i++)
        {
            char x = s[i];
            char y = t[i];
            //找到
            if ((m1.count(x)&&m1[x]!=y) || (m2.count(y) && m2[y] != x))
            {
                return false;
            }
            //未找到
            else
            {
                m1[x] = y;
                m2[y] = x;
            }
        }
        return true;
    }

    //哈希表映射为数字存入数组判断
    bool isIsomorphic2(std::string s, std::string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        std::unordered_map<char, int> map;
        std::vector<int> a;
        std::vector<int> b;
        int num = 1;
        for (int i = 0; i < s.length(); i++)
        {
            //未找到
            if (!map.count(s[i]))
            {
                a.push_back(num);
                map[s[i]] = num;
                num++;
            }
            //找到
            else
            {
                a.push_back(map.at(s[i]));
            }
        }
        map.clear();
        num = 1;
        for (int i = 0; i < t.length(); i++)
        {
            if (!map.count(t[i]))
            {
                b.push_back(num);
                map[t[i]] = num;
                num++;
            }
            else
            {
                b.push_back(map.at(t[i]));
            }
        }
        return a == b;
    }
    void test()
    {
        std::string s1 = "paper";
        std::string s2 = "title";
        std::cout<<isIsomorphic1(s1, s2);
    }
};