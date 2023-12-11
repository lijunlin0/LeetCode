#pragma once

/*
���ƣ��Ҳ�ͬ

���������������ַ��� s �� t ������ֻ����Сд��ĸ���ַ��� t ���ַ��� s ������ţ�Ȼ�������λ�����һ����ĸ�����ҳ��� t �б���ӵ���ĸ��

����˼·��������������һ��26��С�������Ӧ26��Сд��ĸ����һ�齫��Ӧλ��+1����2���ҵ���һ��-1��Ϊ-1��λ��
*/

#include<iostream>

class LeetCode0389 {
public:
    //������
    char findTheDifference1(std::string s, std::string t) {
        int alphabet[26] = { 0 };
        for (char c : s)
        {
            alphabet[c - 'a']++;
        }
        for (char c : t)
        {
            if (alphabet[c - 'a'] - 1 == -1)
            {
                return c;
            }
            else
            {
                alphabet[c - 'a']--;
            }
        }
        return ' ';
    }
    //λ����
    char findTheDifference2(std::string s, std::string t) {
        int ret = 0;
        for (char c : s)
        {
            ret ^= c;
        }
        for (char c : t)
        {
            ret ^= c;
        }
        return ret;
    }

    void test()
    {
        std::cout<<findTheDifference2("abcd", "abfcd");
    }
};