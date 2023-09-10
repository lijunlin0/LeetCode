#pragma once

/*
���ƣ�x ��ƽ����

������
����һ���Ǹ����� x �����㲢���� x �� ����ƽ���� ��
���ڷ������������������ֻ���� �������� ��С�����ֽ��� ��ȥ ��
ע�⣺������ʹ���κ�����ָ����������������� pow(x, 0.5) ���� x ** 0.5 ��

����˼·�����ֲ��ҷ�
*/

#include<iostream>

class LeetCode0069
{
public:
    int mySqrt(int x) {
        int i = 1;
        int j = x;
        int ans = 0;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (mid > x / mid)
            {
                j = mid - 1;
            }
            else
            {
                ans = mid;
                i = mid + 1;
            }
        }
        return ans;
    }
    void test()
    {
        std::cout<<mySqrt(900);
    }
};
