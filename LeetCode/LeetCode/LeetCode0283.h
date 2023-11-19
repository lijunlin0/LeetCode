#pragma once

/*
���ƣ��ƶ���

����������һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
      ��ע�� �������ڲ���������������ԭ�ض�������в�����

����˼·�����α�������һ�α����������������Ʋ���¼��0���������ڶ��α����ڽ�β��ֵ��¼���ĸ�����0��
         һ�α������ڱ���;�в�ͣ��i��jָ�뾭�н����ﵽ�ƶ�0��Ч����
         ͨ������ָ��������ؽ�jָ��ָ��0��iָ��ָ�����Ԫ�ء�
*/

#include<iostream>
#include<vector>

class LeetCode0283 {
public:
    //һ�α���
    void moveZeroes1(std::vector<int>& nums) {
        int i = 0;
        int j = 0;
        for (; i < nums.size(); i++)
        {
            //��������Ԫ��
            if (nums[i] != 0)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }
    }

    //���α���
    void moveZeroes2(std::vector<int>&nums) {
        int i = 0;
        int j = 0;
        //����Ԫ������
        for (; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }
        //��ֵ0
        for (; j < nums.size(); j++)
        {
            nums[j] = 0;
        }
    }

    void test()
    {
        std::vector<int> nums = { 1,1,0,3,12 };
        moveZeroes1(nums);
        for (int i = 0; i < nums.size(); i++)
        {
            std::cout << nums[i] << ',';
        }
    }
};