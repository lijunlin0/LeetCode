#pragma once

/*
���ƣ�4����

����������һ��������дһ���������ж����Ƿ��� 4 ���ݴη�������ǣ����� true �����򣬷��� false ��
      ���� n �� 4 ���ݴη������㣺�������� x ʹ�� n == 4x

����˼·���ж��Ƿ���2���ݴη�����ȡģ��3����1��
*/

#include<iostream>

class LeetCode0342 {
public:
    //ȡģ����
    bool isPowerOfFour1(int n) 
    {
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }

    //�Գ���
    bool isPowerOfFour2(int n) 
    {
        while (n && n % 4 == 0)
        {
            n /= 4;
        }
        return n == 1;
    }

    void test()
    {
        std::cout << (isPowerOfFour1(16) ? "true" : "false");
    }
};