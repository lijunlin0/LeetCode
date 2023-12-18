#pragma once

/*
���ƣ����������

����������һ���ǿ����飬���ش������� ��������� ����������ڣ��򷵻���������������

����˼·���������������ֱ��ʾǰ����С�����֣���������ı����С�����ϴ�ֵ�ı�ʱ����СʱӦ�̳�֮ǰ�Ľϴ�ֵ��
*/

#include<iostream>
#include<vector>

class LeetCode0414 {
public:
    int thirdMax(std::vector<int>& nums) {
        long one = LONG_MIN;
        long two = LONG_MIN;
        long res = LONG_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            //�����ֵ��
            if (nums[i] > one)
            {
                res = two;
                two = one;
                one = nums[i];
            }
            //�ȵڶ���ֵ��
            else if (one > nums[i] && nums[i] > two)
            {
                res = two;
                two = nums[i];
            }
            //�ȵ�����ֵ��
            else if (two > nums[i] && nums[i] > res)
            {
                res = nums[i];
            }
        }
        return res == LONG_MIN ? one : res;
    }

    void test()
    {
        std::cout << thirdMax(std::vector<int>()={2,2,3,1});
    }
};