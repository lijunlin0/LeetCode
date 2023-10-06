#pragma once
/*
���ƣ�ֻ����һ�ε�����

����������һ�� �ǿ� �������� nums ������ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨����������⣬�Ҹ��㷨ֻʹ�ó�������ռ䡣

����������ʣ�1.�κ����� 0 ��������㣬�����Ȼ��ԭ���������� a��0=a��
             2.�κ�������������������㣬����� 0���� a��a=0��
             3.����������㽻���ɺͽ���ɣ��� a��b��a=b��a��a=b��(a��a)=b��0=b��

����˼·�������������� 2m+1 ������������ m �������������Σ�һ��������һ�Ρ�
�����������ʿ�֪��������ͬ������������������0����������ͬ����������������ȫΪ0�����ʣ����Ǹ������ǳ���һ�ε�����
���Խ�������������������õ��ı��Ǵ𰸡�
*/
#include<iostream>
#include<vector>

class LeetCode0136 {
public:
    //�������  
    int singleNumber1(std::vector<int>& nums) {
        int ret = 0;
        for (int e = 0; e < nums.size(); e++)
        {
            //�����������
            ret ^= nums[e];
        }
        return ret;
    }
    //����ѭ��
    int singleNumber2(std::vector<int>& nums) 
    {   
        for (int i = 0; i < nums.size(); i++)
        {
            bool found = true;
            for (int j = 0; j < nums.size(); j++)
            {
                if (j==i)
                {
                    continue;
                }
                if (nums[j] == nums[i])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                return nums[i];
            }
        }
        return 0;
    }

    void test()
    {
        std::vector<int> nums = { 2,2,1};
        std::cout<<singleNumber1(nums);
    }
};
