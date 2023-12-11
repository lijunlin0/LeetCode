#pragma once

/*
���ƣ�����ת��Ϊʮ��������

����������һ����������дһ���㷨�������ת��Ϊʮ�������������ڸ�����������ͨ��ʹ�� �������� ������

ע��:
ʮ��������������ĸ(a-f)��������Сд��
ʮ�������ַ����в��ܰ��������ǰ���㡣���Ҫת������Ϊ0����ô�Ե����ַ�'0'����ʾ���������������ʮ�������ַ����еĵ�һ���ַ���������0�ַ���
��������ȷ����32λ�з���������Χ�ڡ�
����ʹ���κ��ɿ��ṩ�Ľ�����ֱ��ת�����ʽ��Ϊʮ�����Ƶķ���

����˼·����������ת��Ϊ�޷������;��ǽ��в�������
*/

#include<iostream>

class LeetCode0405 {
public:
    std::string toHex(int num) {
        std::string s = "";
        if (num == 0)
        {
            return "0";
        }
        //ת��Ϊ�޷������;��ǲ�������
        unsigned int uNum = static_cast<unsigned int>(num);  // תΪ�޷�������
        while (uNum > 0)
        {
            long temp = uNum % 16;
            uNum /= 16;
            s += to_16(temp);
        }
        //��ת
        std::reverse(s.begin(), s.end());
        return s;
    }

    char to_16(int num)
    {
        switch (num)
        {
        case 0:return '0'; break;
        case 1:return '1'; break;
        case 2:return '2'; break;
        case 3:return '3'; break;
        case 4:return '4'; break;
        case 5:return '5'; break;
        case 6:return '6'; break;
        case 7:return '7'; break;
        case 8:return '8'; break;
        case 9:return '9'; break;
        case 10:return 'a'; break;
        case 11:return 'b'; break;
        case 12:return 'c'; break;
        case 13:return 'd'; break;
        case 14:return 'e'; break;
        case 15:return 'f'; break;
        default:return ' ';
        }
    }

    void test()
    {
        std::cout << toHex(-1);
    }
};