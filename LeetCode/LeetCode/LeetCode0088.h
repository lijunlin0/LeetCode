#pragma once
/*
名称：合并两个有序数组

描述：
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，
其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

解题思路：逆向双指针：用两个指针指向两个数组末尾逆向遍历，将较大值放入nums1末尾的多余位置。（优点：不需要使用额外空间）
*/
#include<iostream>
#include<vector>
#include<algorithm>

class LeetCode0088
{
public:
    //逆向双指针（优解）
    void merge1(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        while (p1 >= 0 || p2 >= 0)
        {
            if (p1 == -1) 
            {
                nums1[tail--] = nums2[p2--];
            }
            else if (p2 == -1) 
            {
                nums1[tail--] = nums1[p1--];
            }
            else if (nums1[p1] > nums2[p2]) 
            {
                nums1[tail--] = nums1[p1--];
            }
            else 
            {
                nums1[tail--] = nums2[p2--];
            }
        }
    }

    //直接合并后排序
    void merge2(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }

    void test()
    {
        std::vector<int> nums1 = { 1,3,5,7,9,0,0,0,0,0};
        std::vector<int> nums2 = { 2,4,6,8,10 };
        merge1(nums1, 5, nums2, nums2.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            std::cout << nums1[i]<<' ';
        }
    }
};
