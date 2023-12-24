#pragma once

/*
���ƣ�����Ӳ��

���������ܹ��� n öӲ�ң����ƻ������ǰ�����״���С�����һ���� k ����ɵĽ��ݣ���� i �б��������� i öӲ�ҡ����ݵ����һ�� ���� �ǲ������ġ�
      ����һ������ n �����㲢���ؿ��γ� ���������� ����������

����˼·��1.����
         2.���ַ�
*/

#include<iostream>

class LeetCode0441 {
public:
    //���ַ�
    int arrangeCoins1(int n) {
        int left = 1;
        int right = n;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            long long coins = (long long)mid * (mid + 1) / 2;
            //�ҵ���������
            if (coins == n)
            {
                return mid;
            }
            //���������������Ұ벿��
            else if (coins < n)
            {
                left = mid + 1;
            }//�������࣬������벿��
            else
            {
                right = mid - 1;
            }
        }
        //�б߽�Ϊ�������������
        return right;
    }

    //����
    int arrangeCoins2(int n) {
        //�������������
        int result = 0;
        //��ǰ���ݸ�����
        int i = 1;
        while (n >= 0)
        {
            n -= i;
            result++;
            i++;
        }
        return result - 1;
    }


    void test()
    {
        std::cout<<arrangeCoins2(5);
    }
};