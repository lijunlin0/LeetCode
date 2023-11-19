#pragma once

/*
���ƣ�����

���������� ����ֻ���������� 2��3 �� 5 ����������
     ����һ������ n �������ж� n �Ƿ�Ϊ ���� ������ǣ����� true �����򣬷��� false ��

����˼·����2��3��5�������ֱ����������ж��Ƿ�Ϊ1.
*/

#include<iostream>

class LeetCode0263
{
public:
    bool isUgly(int n) {
        if (n <= 0)
        {
            return false;
        }
        while (n % 2 == 0)
        {
            n /= 2;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        while (n % 5 == 0)
        {
            n /= 5;
        }
        return n == 1;
    }

    void test()
    {
        std::cout << (isUgly(6)?"true":"false");
    }
};