#pragma once

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/*
���ƣ���һ������İ汾

�������������� n ���汾 [1, 2, ..., n]�������ҳ�����֮�����а汾����ĵ�һ������İ汾��
     �����ͨ������ bool isBadVersion(version) �ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г���
     ʵ��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ��� API �Ĵ�����

ʾ����
���룺n = 5, bad = 4
�����4
���ͣ�
���� isBadVersion(3) -> false
���� isBadVersion(5) -> true
���� isBadVersion(4) -> true
���ԣ�4 �ǵ�һ������İ汾��

����˼·�����ֲ��ҷ�
*/

#include<iostream>

class LeetCode0278 {
public:
    bool isBadVersion(int n)
    {
        return n == 4;
    }
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    void test()
    {
        std::cout<< firstBadVersion(5);
    }
};