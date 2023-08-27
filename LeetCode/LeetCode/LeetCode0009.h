#pragma once
/*
����: ������

����:
����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��
��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

����˼·:
��תһ��ĵ��ַ�:����벿�ֺ�ǰ�벿��������� ���磺1221
��1221%10�õ����һλ��1���ٽ�ԭ������1221/10�õ�ȥ��ĩβ������122���ٽ�����%10�õ������ڶ�����2������һ����1*10+2�õ���ת��������ٽ�122/10�õ�12��
���⣬������xΪ����ʱ������12321 ��Ϊ��λ�����Ǻ��Լ���ȣ���Ӱ���жϣ�����ֻ��Ҫ����ת��/10����λ��ȥ����
������������ת��С�ڻ��ߵ���ԭ������ʱ��
*/
#include<iostream>
#include<vector>
using namespace std;

class LeetCode0009 {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0))
        {
            return false;
        }
        int reverted_number = 0;
        while (x > reverted_number)
        {
            reverted_number = reverted_number * 10 + x % 10;
            x /= 10;
        }
        return x == reverted_number || x == reverted_number / 10;
    }
    void test()
    {
        cout<<isPalindrome(12321);
    }
};

