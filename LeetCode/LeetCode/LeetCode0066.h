#pragma once
/*
���ƣ���һ

������
����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
����Լ���������� 0 ֮�⣬��������������㿪ͷ��

����˼·�������һλ����ʼ���������������1����10����Ҫ��λ�����򽫸�λ��ֵΪ0��ֱ������������1������10������Ҫ��λ�����������һ�󷵻أ���ѭ��������δ��������ζ�Ÿ������е�ֵȫΪ9��Ӧ�����ײ�����һ��1�󷵻ء�
*/
#include<vector>
#include<iostream>
using namespace std;

class LeetCode0066 {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int temp = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            if (digits[i] + 1 == 10)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }

    void test()
    {
        vector<int> nums = { 9,9,9,9 };
        nums=plusOne(nums);
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << ' ';
        }
    }
};
