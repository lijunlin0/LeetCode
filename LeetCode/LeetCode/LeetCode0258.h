#pragma once

/*
���ƣ���λ���

����������һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����������������

����˼·��˫��ѭ����ÿ��ȡ�����һλ�������ۼӡ�
*/

#include<iostream>

class LeetCode0258 {
public:
    int addDigits(int num) {
        while (num >= 10)
        {
            int sum = 0;
            while (num)
            {
                sum += num % 10;;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }

    void test()
    {
        std::cout<<addDigits(567);
    }
};