#pragma once

/*
���ƣ�3 ����

����������һ��������дһ���������ж����Ƿ��� 3 ���ݴη�������ǣ����� true �����򣬷��� false ��
      ���� n �� 3 ���ݴη������㣺�������� x ʹ�� n == 3x��

����˼·������һ��3����n�������Լ����Ȼ���ڱ�����ϵ(�˷���ֻ����������)��
         ���������� n �� 3 �����Գ���ֱ�� n ������ 3 �ʱ�����ϵ������ж� n==1 ���ɡ�

*/

#include<iostream>

class LeetCode0326 {
public:
    //���Լ��
    bool isPowerOfThree1(int n) 
    {
        return n > 0 && 1162261467 % n == 0;
    }
    //�Գ���
    bool isPowerOfThree2(int n) {
        while (n && n % 3 == 0) 
        {
            n /= 3;
        }
        return n == 1;
    }

    void test()
    {
        std::cout << (isPowerOfThree1(27) ? "true" : "false");
    }
};