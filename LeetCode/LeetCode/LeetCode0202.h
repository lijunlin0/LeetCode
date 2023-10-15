#pragma once
/*
���ƣ�������

������
��дһ���㷨���ж�һ���� n �ǲ��ǿ�������
���������� ����Ϊ��
����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
���������� ���Ϊ 1����ô��������ǿ�������
��� n �� ������ �ͷ��� true �����ǣ��򷵻� false ��

ʾ����
���룺n = 19
�����true
���ͣ�
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

����˼·������ָ�룺��ÿ�μ����ֵ����һ����ʽ�����У���ָ��ÿ����һ������ָ��ÿ������������������޻����ǿ���������֮���ǡ�
*/

#include<iostream>

class LeetCode0202 {
public:
    //������һ��ֵ
    int get_next(int n)
    {
        int num = 0;
        while (n > 0)
        {
            num += (n % 10) * (n % 10);
            n /= 10;
        }
        return num;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = get_next(n);
        while (fast != 1 && fast != slow)
        {
            //��һ��
            slow = get_next(slow);
            //������
            fast = get_next(get_next(fast));
        }
        return fast == 1;
    }

    void test()
    {
        std::cout << isHappy(19);
    }
};