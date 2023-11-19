#pragma once

/*
���ƣ���Ч����ĸ��λ��

���������������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�

ע�⣺�� s �� t ��ÿ���ַ����ֵĴ�������ͬ����� s �� t ��Ϊ��ĸ��λ��

����˼·���ַ���ֻ���� 26 ��Сд��ĸ������һ����СΪ26�����飬�ڶ�Ӧλ�ô������ַ��Ĵ�����
         s�ַ��������ۼӣ�t�ַ������ۼ��������ַ�����Ϊ��ĸ��λ�ʣ���������ÿ������ӦΪ0��
*/

#include<unordered_set>
#include<iostream>

class LeetCode0242 {
public:
    //��ϣӳ��
    bool isAnagram1(std::string s, std::string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        int char_arr[26] = { 0 };
        //����
        for (int i = 0; i < s.size(); i++)
        {
            char_arr[s[i] - 'a']++;
            char_arr[t[i] - 'a']--;
        }
        //�ж�
        for (int i = 0; i < 26; i++)
        {
            if (char_arr[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    //multset�����洢�����ַ����ַ����Ƚ����ַ���
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
            //��Ӽ�ֵ��
            m1.emplace(s[i]);
        }
        std::cout << m1.size() << std::endl;
        for (int i = 0; i < t.size(); i++)
        {
            //��Ӽ�ֵ��
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