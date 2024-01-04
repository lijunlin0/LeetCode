#pragma once

/*
���ƣ�Ѱ�����������������λ��

����������������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��

Ҫ���㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��

����˼·��1.�ϲ������飺�ϲ������������������С�����м��������м���������ƽ��ֵ��         
         2.���ֲ��ң����úϲ��������飬�ҵ���λ����λ�ã�Ҳ���ǵ�k�����
*/ 

#include<iostream>
#include<vector>
#include <queue>

class LeetCode0004 {
public:

    int getk(const std::vector<int>& nums1, const std::vector<int>& nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0;
        int index2 = 0;

        while (true)
        {
            //����1�ߵ������ֱ�ӷ�������2��k�������
            if (index1 == m)
            {
                return nums2[index2 + k - 1];
            }
            //����2�ߵ������ֱ�ӷ�������1�е�k�������
            if (index2 == n)
            {
                return nums1[index1 + k - 1];
            }
            //���һ����ֱ���ж�
            if (k == 1)
            {
                return std::min(nums1[index1], nums2[index2]);
            }
            //�������
            //ÿ��ȡk/2��λ�ã������鲻���ˣ���ȡ�������һ��λ��
            int newIndex1 = std::min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
            int num1 = nums1[newIndex1];
            int num2 = nums2[newIndex2];
            //���num1<=num2���������б�num1С�ĸ���ֻ�� k/2���������Խ����ų���һ�ξ��ų���һ�롣
            if (num1 <= num2)
            {
                //k��ȥ�Ѿ��ų��ĸ���
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays1(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int totalLength = nums1.size() + nums2.size();
        //��������С��Ϊ����---�����м���
        if (totalLength % 2 == 1)
        {
            return getk(nums1, nums2, (totalLength + 1) / 2);
        }
        //��������С��Ϊż��---�����м���������ƽ��ֵ
        else
        {
            return (getk(nums1, nums2, totalLength / 2) + getk(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }

    double findMedianSortedArrays2(std::vector<int>& nums1, std::vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();
        if (nums1.size() % 2 == 0)
        {
            return ((double)nums1[(n - 1) / 2] + nums1[n / 2]) / 2;
        }
        else
        {
            return nums1[n / 2];
        }
    }



    void test()
    {
        std::cout << findMedianSortedArrays1(std::vector<int>() = {1,3}, std::vector<int>() = {2});
    }
};