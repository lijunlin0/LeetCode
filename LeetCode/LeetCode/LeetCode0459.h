#pragma once

/*
���ƣ��ظ������ַ���

����������һ���ǿյ��ַ��� s ������Ƿ����ͨ��������һ���Ӵ��ظ���ι��ɡ�

����˼·������ַ��� S ����һ���ظ������ַ�������ô����ζ�������Զ�� ����λ�ͻ��С�`�����ַ�������ʹ����ԭʼ�ַ���ƥ�䡣
         Ϊ�����Ч�ʣ����Դ���һ���µ��ַ��� str��������ԭ�����ַ��� S �ټ��� S ����������ʵ�Ͱ����������ƶ����ַ�����
         ���Կ���ֱ���ж� str ��ȥ����βԪ��֮���Ƿ��������Ԫ�ء��������������������ظ��Ӵ���
*/

#include<iostream>

class LeetCode0459 {
public:
    bool repeatedSubstringPattern(std::string s) {
        std::string str = s + s;
        return str.substr(1, str.size() - 2).find(s) == -1 ? false : true;
    }

    void test()
    {
        std::cout << (repeatedSubstringPattern("abc") ? "true" : "false");
    }
};