#pragma once

/*
���ƣ���ת�ַ���

��������дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
     ��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣

����˼·��˫ָ�뽻��
*/

#include<iostream>
#include<vector>

class LeetCode0344 {
public:
    void reverseString(std::vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i <= j; i++, j--)
        {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
    }

    void test()
    {
        std::vector<char> s = { 'h','e','l','l','o'};
        reverseString(s);
        for (int i = 0; i < s.size(); i++)
        {
            std::cout << s[i] << ' ';
        }

    }
};