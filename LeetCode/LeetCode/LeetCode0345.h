#pragma once

/*
���ƣ���ת�ַ����е�Ԫ����ĸ

����������һ���ַ��� s ������ת�ַ����е�����Ԫ����ĸ�������ؽ���ַ�����
      Ԫ����ĸ���� 'a'��'e'��'i'��'o'��'u'���ҿ����Դ�Сд������ʽ���ֲ�ֹһ�Ρ�

      
����˼·��˫ָ��ָ����β����������ָ��ֱ�ָ���һ��Ԫ����ĸ��Ȼ��ͽ��н�����
*/

#include<vector>
#include<iostream>

class LeetCode0345 {
public:
    std::string reverseVowels(std::string s) 
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            //�ֱ��ҵ���һ��Ԫ����ĸ
            while (i < s.size() - 1 && s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
            {
                i++;
            }
            while (j > 0 && s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U')
            {
                j--;
            }
            if (i < j)
            {
                std::swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }

    void test()
    {
        std::cout << reverseVowels("hello");
    }

};