#pragma once
/*
���ƣ����һ�����ʵĳ���

����������һ���ַ��� s�������ɵ�����ɣ�����ǰ����һЩ�ո��ַ������������ַ����� ���һ�� ���ʵĳ��ȡ�

����˼·���������������һ��ѭ����i�����ո�Ȼ��ͨ��i������ĸ����������ÿ����ĸ�����ǵ��ʵĳ��ȣ�ֱ���ҵ�һ���ո�Ϊֹ��
*/
#include<iostream>
using namespace std;

class LeetCode0058
{
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int num = 0;
        //������β�ո�
        while (s[i] == ' ')
        {
            i--;
        }
        while (i >= 0 && s[i] != ' ')
        {
            num++;
            i--;
        }
        return num;
    }
    void test()
    {
        string s = " fly to  the  moon   ";
        cout << lengthOfLastWord(s);
    }
};