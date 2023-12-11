#pragma once

/*
���ƣ�����Ĵ�

����������һ��������д��ĸ��Сд��ĸ���ַ��� s ������ ͨ����Щ��ĸ����ɵ� ��Ļ��Ĵ� ��
     �ڹ�������У���ע�� ���ִ�Сд ������ "Aa" ���ܵ���һ�������ַ�����

����˼·������һ��128��С���������飬��֤ÿ����ĸ���ܶ�Ӧ�������ַ���s���������ż������ĸ�򽫽����2������жϽ�����ַ����Ĵ�С��ϵ�ж��Ƿ��1��    
*/

#include<iostream>
#include<set>

class LeetCode0409
{
public:
    int longestPalindrome(std::string s) {
        int temp[128] = { 0 };
        //���
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            //��Ӧ��ĸ��1
            temp[c]++;
            //����ż��
            if (temp[c] == 2)
            {
                ans += 2;
                temp[c] = 0;
            }
        }
        //����ʣ����ĸ���1
        return ans < s.size() ? ans + 1 : ans;
    }

    void test()
    {
        std::cout<<longestPalindrome("abccccdd");
    }
};