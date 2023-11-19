#pragma once

/*
���ƣ����ʹ���

����������һ�ֹ��� pattern ��һ���ַ��� s ���ж� s �Ƿ���ѭ��ͬ�Ĺ��ɡ�
����� ��ѭ ָ��ȫƥ�䣬���磬 pattern ���ÿ����ĸ���ַ��� s �е�ÿ���ǿյ���֮�������˫�����ӵĶ�Ӧ���ɡ�

����˼·:����һ��mapͨ��ӳ�����ж��Ƿ���Ϲ���
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
                //�Ƿ��ҵ�
                bool find = false;
                for (std::unordered_map<std::string, char>::iterator it = ps.begin(); it != ps.end(); it++)
                {
                    if (it->second==pattern[j])
                    {
                        if (it->first == str)
                        {
                            find = true;
                        }
                        //�Ƿ�ƥ��
                        else
                        {
                            return false;
                        }
                    }
                    //�Ƿ�ƥ��
                    else if (it->first == str&&it->second!=pattern[j])
                    {
                        return false;
                    }
                }
                //δ�ҵ�
                if (!ps.count(str) && !find)
                {
                    ps[str] = pattern[j];
                }
                j++;
            }
        }
        //�Ƿ����������ַ���
        return j==pattern.size();
    }

    void test()
    {
        std::string pattern = "abba";
        std::string s = "dog cat cat dog";
        std::cout<<(wordPattern(pattern, s)?"true":"false");
    }
};
