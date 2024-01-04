#pragma once

/*
名称：寻找两个正序数组的中位数

描述：给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

要求：算法的时间复杂度应该为 O(log (m+n)) 。

解题思路：1.合并两数组：合并两个数组后根据数组大小返回中间数或者中间两个数的平均值。         
         2.二分查找：不用合并两个数组，找到中位数的位置，也就是第k大的数
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
            //数组1走到了最后，直接返回数组2第k大的数字
            if (index1 == m)
            {
                return nums2[index2 + k - 1];
            }
            //数组2走到了最后。直接返回数组1中第k大的数字
            if (index2 == n)
            {
                return nums1[index1 + k - 1];
            }
            //最后一个，直接判断
            if (k == 1)
            {
                return std::min(nums1[index1], nums2[index2]);
            }
            //正常情况
            //每次取k/2个位置，若数组不够了，则取数组最后一个位置
            int newIndex1 = std::min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
            int num1 = nums1[newIndex1];
            int num2 = nums2[newIndex2];
            //如果num1<=num2则在数组中比num1小的个数只有 k/2个数，可以将其排除，一次就排除了一半。
            if (num1 <= num2)
            {
                //k减去已经排除的个数
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
        //如果数组大小和为奇数---返回中间数
        if (totalLength % 2 == 1)
        {
            return getk(nums1, nums2, (totalLength + 1) / 2);
        }
        //如果数组大小和为偶数---返回中间两个数的平均值
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