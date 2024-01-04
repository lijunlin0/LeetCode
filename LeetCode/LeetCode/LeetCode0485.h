#pragma once

/*
���ƣ�������� 1 �ĸ���

����������һ������������ nums �� ��������������� 1 �ĸ�����

����˼·������
*/

#include<iostream>
#include<vector>

class LeetCode0485 {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int temp = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                temp++;
            }
            else
            {
                res = std::max(temp, res);
                temp = 0;
            }
        }
        //��β�ж�һ��
        return std::max(temp, res);;
    }

    void test()
    {
        std::cout << findMaxConsecutiveOnes(std::vector<int>() = { 1,1,0,1,1,1 });
    }
};
