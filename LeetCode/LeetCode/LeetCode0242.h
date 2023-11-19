#pragma once

/*
名称：有效的字母异位词

描述：给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词

解题思路：字符串只包含 26 个小写字母，创建一个大小为26的数组，在对应位置代表其字符的次数，
         s字符串负责累加，t字符负责累减，若两字符串互为字母异位词，则数组中每个数都应为0。
*/

#include<unordered_set>
#include<iostream>

class LeetCode0242 {
public:
    //哈希映射
    bool isAnagram1(std::string s, std::string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        int char_arr[26] = { 0 };
        //操作
        for (int i = 0; i < s.size(); i++)
        {
            char_arr[s[i] - 'a']++;
            char_arr[t[i] - 'a']--;
        }
        //判断
        for (int i = 0; i < 26; i++)
        {
            if (char_arr[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    //multset容器存储两个字符串字符，比较其字符数
    bool isAnagram2(std::string s, std::string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        std::unordered_multiset<char> m1;
        std::unordered_multiset<char> m2;
        for (int i = 0; i < s.size(); i++)
        {
            //添加键值对
            m1.emplace(s[i]);
        }
        std::cout << m1.size() << std::endl;
        for (int i = 0; i < t.size(); i++)
        {
            //添加键值对
            m2.emplace(t[i]);
        }
        std::cout << m2.size() << std::endl;
        for (std::unordered_set<char>::iterator i = m1.begin(); i != m1.end(); i++)
        {
            if (m1.count(*i)!=m2.count(*i))
            {
                return false;
            }
        }
        return true;
    }

    void test()
    {
        std::string s = "aacc";
        std::string t = "ccac";
        std::cout<<(isAnagram1(s, t)?"true":"false")<<std::endl;
    }
};