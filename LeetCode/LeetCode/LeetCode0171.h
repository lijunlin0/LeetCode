#pragma once
/*
���ƣ�Excel �������

����������һ���ַ��� columnTitle ����ʾ Excel ����е������ơ����� �������ƶ�Ӧ������� ��

����˼·��������һ��26����ת��10���Ƶ��⣬�Ӻ���ǰ���������������������Ӧλ����
*/

#include<iostream>

class LeetCode0171 {
public:
    int titleToNumber(std::string columnTitle) {
        int num = 0;
        //��¼λ��
        long temp = 1;
        for (int i = columnTitle.length() - 1; i >= 0; i--)
        {
            //��ǰλ������
            int k = columnTitle[i] - 'A' + 1;
            //����ǰλ�����ֳ���Ӧ��λ���ټ���֮ǰ��ֵ
            num += k * temp;
            //��λ
            temp *= 26;
        }
        return num;
    }


    void test()
    {
        std::cout << titleToNumber("ABC");
    }
};
