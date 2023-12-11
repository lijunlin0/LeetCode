#pragma once

/*
���ƣ��ַ����еĵ�һ��Ψһ�ַ�

����������һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� -1 ��

����˼·��������������һ��26��С�������Ӧ26��Сд��ĸ����һ�齫��Ӧλ��+1����2���ҵ���һ��-1��Ϊ1��λ��
*/

#include<iostream>
#include<map>
class LeetCode0387 {
public:
    int firstUniqChar(std::string s) {
        int m[26] = { 0 };
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
    void test()
    {
        std::cout<<firstUniqChar("leetcode");
    }
    
};