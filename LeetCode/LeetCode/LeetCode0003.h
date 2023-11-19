#pragma once

/*
���ƣ����ظ��ַ�����Ӵ�

����������һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

����˼·���������ڣ�����һ���ַ�����leftΪ������ࣻ
                  1.�ҵ��ظ��ַ�---ѭ��ɾ�����ظ�ֵ��
                  2.δ�ҵ�ʱ---���ֵ��set���ı����ֵ
*/

#include<iostream>
#include<unordered_set>

class LeetCode0003 {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() == 0)
        {
            return 0;
        }
        std::unordered_set<char> set;
        //���ֵ
        int max_str = 0;
        //�������
        int left = 0;
        //�����ַ���
        for (int i = 0; i < s.size(); i++)
        {
            //�ҵ��ظ��ַ�---ѭ��ɾ�����ظ�ֵ��
            while (set.find(s[i]) != set.end())
            {
                set.erase(s[left]);
                left++;
            }
            //δ�ҵ�ʱ---���ֵ��set���ı����ֵ
            max_str = std::max(max_str, i - left + 1);
            set.emplace(s[i]);
        }
        return max_str;
    }

    void test()
    {
        std::string s = "abcabcbb";
        std::cout << lengthOfLongestSubstring(s);
    }
};