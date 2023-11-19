#pragma once

/*
���ƣ���ʧ������

����������һ������ [0, n] �� n ���������� nums ���ҳ� [0, n] �����Χ��û�г����������е��Ǹ�����

����˼·��������㣺�κ�����0��������㣬�����Ȼ��ԭ���������� a ^ 0 = a��
                  �κ�������������������㣬�����0���� a ^ a = 0��
                  ��һ�α����Դ� 0 �� n �����������������������ڶ��α����������е�ÿһ����������������
                  ���ս������ȱʧ������
*/

#include<iostream>
#include<vector>
#include <queue>

class LeetCode0268 {
public:
    //�������
    int missingNumber1(std::vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            ans ^= i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
    //����
    int missingNumber2(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int a = 0; a < nums.size(); a++)
        {
            if (a != nums[a])
            {
                return a;
            }
        }
        return nums.size();
    }

    void test()
    {
        std::vector<int> nums = { 0,1,2,4,5,6,7,8,9 };
        std::cout << missingNumber1(nums);
    }
};