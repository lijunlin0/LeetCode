#pragma once
/*
���ƣ�Excel��������

����������һ������ columnNumber ���������� Excel �������Ӧ�������ơ�
���磺
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

����˼·��ʵ����һ��ʮ����ת��26���Ƶ���Ŀ������������[1,26]������Ӧ���Ƚ��м�һ��

*/

#include<iostream>

class LeetCode0168 {
public:
    std::string convertToTitle(int columnNumber) {
        std::string str;
        while (columnNumber > 0)
        {
            columnNumber--;
            str += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        //�ַ���ת
        reverse(str.begin(), str.end());
        return str;
    }

    void test()
    {
        std::cout<<convertToTitle(731);
    }
};
