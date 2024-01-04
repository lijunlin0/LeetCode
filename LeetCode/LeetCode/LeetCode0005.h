#pragma once

/*
���ƣ�������Ӵ�

����������һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
     ����ַ����ķ�����ԭʼ�ַ�����ͬ������ַ�����Ϊ�����ַ�����

����˼·��1.������ɢ��������s��ÿ���±꣬��������ɢ�ҵ��������ַ�����
         2.�����ⷨ�������������ж����±��ڵ��ַ����Ƿ�Ϊ�������ַ�����
*/

#include<iostream>
#include<vector>
#include <string>

class LeetCode0005 {
public:

    //������ɢ��
    std::string longestPalindrome1(std::string s) {
        //��һ��λ�ü�¼��ʼ�±꣬�ڶ���λ�ü�¼���Ĵ�����
        std::vector<int> res = { 0,1 };
        int max_len = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            //������ɢ����
            std::vector<int> odd = { 0,1 };
            //ż����ɢ����
            std::vector<int> even = { 0,1 };
            center(odd, s, i, i);
            center(even, s, i, i + 1);
            //ȡ��ż����ɢ�ϴ������
            std::vector<int> max_temp = odd[1] > even[1] ? odd : even;
            if (max_temp[1] > max_len)
            {
                res = max_temp;
                max_len = max_temp[1];
            }
        }
        //�ü��������Ĵ�
        return s.substr(res[0], res[1]);
    }

    //������ɢ���ı����õ�����Ϊ��ɢ���������Ĵ�
    void center(std::vector<int>& res, std::string& s, int left, int right)
    {
        int n = s.size();
        while (left >= 0 && right < n)
        {
            if (s[left] != s[right])
            {
                break;
            }
            left--;
            right++;
        }
        //+1Ϊ��һ�ε�λ�ã���Ϊ��ɢ���������Ĵ��߽�
        res[0] = left + 1;
        res[1] = right - left - 1;
    }
    
    //�����ⷨ
    std::string longestPalindrome2(std::string s) {
        if (s.size() == 1)
        {
            return s;
        }
        //�����Ĵ�����
        int max = 1;
        //�����Ĵ���ʼ�±�
        int begin = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if ((j - i + 1) > max && is_palindrome(i, j, s))
                {
                    max = j - i + 1;
                    begin = i;
                }
            }
        }
        //�ü��������Ĵ�
        return s.substr(begin, max);
    }

    //�ж���ָ���ڵ��ַ����Ƿ��ǻ��Ĵ�
    bool is_palindrome(int i, int j, std::string& s)
    {
        for (; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
   



    void test()
    {
        std::cout << longestPalindrome1("cbbd");
    }
};