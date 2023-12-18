#pragma once

/*
���ƣ���������ת����

�������������ְ������������ַ�: I�� V�� X�� L��C��D �� M��

�ַ�          ��ֵ
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

���磬 �������� 2 д�� II ����Ϊ�������е� 1 ��12 д�� XII ����Ϊ X + II �� 27 д��  XXVII, ��Ϊ XX + V + II ��
ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�
����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������
I ���Է��� V (5) �� X (10) ����ߣ�����ʾ 4 �� 9��
X ���Է��� L (50) �� C (100) ����ߣ�����ʾ 40 �� 90��
C ���Է��� D (500) �� M (1000) ����ߣ�����ʾ 400 �� 900��
����һ���������֣�����ת����������

����˼·�������ַ����������ַ���Ӧ�����֣��ж� ��һ���ַ���Ӧ������ �Ƿ�� ��ǰ�ַ���Ӧ������ �󣬸������ǵĴ�С��ϵ���мӼ�������
*/

#include<iostream>
class LeetCode0013 {
public:
    int romanToInt(std::string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            //�ж��Ƿ��������ַ���������ַ���
            int value = get_value(s[i]);
            if (i != s.size() - 1 && value < get_value(s[i + 1]))
            {
                res -= value;
            }
            else
            {
                res += value;
            }
        }
        return res;
    }

    int get_value(char c)
    {
        switch (c)
        {
        case'I':return 1; break;
        case'V':return 5; break;
        case'X':return 10; break;
        case'L':return 50; break;
        case'C':return 100; break;
        case'D':return 500; break;
        case'M':return 1000; break;
        default:
            return 0;
        }
    }
    
    void test()
    {
        std::cout<<romanToInt("MIX");
    }
};