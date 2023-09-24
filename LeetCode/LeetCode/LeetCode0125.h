#include<iostream>

/*
���ƣ���֤���Ĵ�

����������ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�� ���Ĵ� ��
��ĸ�����ֶ�������ĸ�����ַ���
����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��

����˼·��˫ָ�룬�߲������ж�
*/

#pragma once
class LeetCode0125 {
public:
    bool isPalindrome(std::string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            //���Ϊ����ĸ�����ַ���i++
            while (i < j && !isalnum(s[i]))
            {
                i++;
            }
            //���Ϊ����ĸ�����ַ���j++
            while (i < j && !isalnum(s[j]))
            {
                j--;
            }
            //���Сд����ַ��������ֱ�ӷ���false
            if (tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
            i++;
            j--;
        }
        //��󷵻�true
        return true;
    }
    void test()
    {
        std::string s = { "A man, a plan, a canal: Panama" };
        std::cout<<isPalindrome(s);
    }
};