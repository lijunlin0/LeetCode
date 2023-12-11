#pragma once

/*
���ƣ��������ִ�С

��������������Ϸ�Ĺ������£�

������ÿ����Ϸ���Ҷ���� 1 �� n ���ѡ��һ�����֡� �����ѡ�������ĸ����֡�
     �����´��ˣ��һ�����㣬��²�����ֱ���ѡ���������Ǵ��˻���С�ˡ�
     �����ͨ������һ��Ԥ�ȶ���õĽӿ� int guess(int num) ����ȡ�²���������ֵһ���� 3 �ֿ��ܵ������-1��1 �� 0����

     -1����ѡ�������ֱ���µ�����С pick < num
      1����ѡ�������ֱ���µ����ִ� pick > num
      0����ѡ�������ֺ���µ�����һ������ϲ����¶��ˣ�pick == num
      ������ѡ�������֡�

����˼·�����ַ�
*/

#include<iostream>

class LeetCode0374 {
public:
    int guessNumber(int n) {
        //�ж�
        auto guess=[n](int num)
        {
                if (num < n)
                    return 1;
                else if (num > n)
                    return -1;
                else
                    return 0;
        };
        int left = 1;
        int right = n;
        while (true)
        {
            int mid = left + (right - left) / 2;
            if (guess(mid) == -1)
            {
                right = mid - 1;
            }
            else if (guess(mid) == 1)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
    }

    void test()
    {
        std::cout<<guessNumber(10);
    }
};
