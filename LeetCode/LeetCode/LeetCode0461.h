#pragma once

/*
���ƣ���������

��������������֮��� �������� ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��
     ������������ x �� y�����㲢��������֮��ĺ������롣

����˼·���Ƚ�x��y���������������x��y��ͬ��λ�ã����ڲ�ͬ��λ��ȫ��1��
         Ȼ�������Ľ��s��s-1���������ͳ��1�ĸ������Ǵ𰸡�
*/

#include<iostream>

class LeetCode0461 {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y;
        int result = 0;
        while (s)
        {
            s &= s - 1;
            result++;
        }
        return result;
    }

    void test()
    {
        std::cout << hammingDistance(1, 4);
    }
};