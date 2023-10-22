#pragma once
/*
���ƣ�ͬ���ַ���

���������������ַ��� s �� t ���ж������Ƿ���ͬ���ġ�
��� s �е��ַ����԰�ĳ��ӳ���ϵ�滻�õ� t ����ô�������ַ�����ͬ���ġ�
ÿ�����ֵ��ַ���Ӧ��ӳ�䵽��һ���ַ���ͬʱ���ı��ַ���˳�򡣲�ͬ�ַ�����ӳ�䵽ͬһ���ַ��ϣ�
��ͬ�ַ�ֻ��ӳ�䵽ͬһ���ַ��ϣ��ַ�����ӳ�䵽�Լ�����

����˼·����ϣ�������ַ������� s�ַ��� ��Ӧ�±���ַ��� t�ַ��� ��Ӧ�±���ַ���Ϊһ���γ�ӳ���ϵ��
                 Ȼ���ж��ַ���ӳ��Ͷ�Ӧ�±���ַ��Ƿ���ͬ��
*/

#include<iostream>
#include<unordered_map>
class LeetCode0205 {
public:
    //��ϣ��ֱ���ж�
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
            //�ҵ�
            if ((m1.count(x)&&m1[x]!=y) || (m2.count(y) && m2[y] != x))
            {
                return false;
            }
            //δ�ҵ�
            else
            {
                m1[x] = y;
                m2[y] = x;
            }
        }
        return true;
    }

    //��ϣ��ӳ��Ϊ���ִ��������ж�
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
            //δ�ҵ�
            if (!map.count(s[i]))
            {
                a.push_back(num);
                map[s[i]] = num;
                num++;
            }
            //�ҵ�
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