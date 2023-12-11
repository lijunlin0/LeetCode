#pragma once

#include<iostream>
#include<vector>
#include <set>

/*
名称：两个数组的交集 II

描述：给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，
     应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

解题思路：将nums1存入multiset（可以存重复元素）中，遍历nums2，和multiset中的nums1比较是否有交集，若找到，则在multiset中删除该位置上的数。
*/

class LeetCode0350 {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::multiset<int> s(nums1.begin(), nums1.end());
        std::vector<int> result;
        for (int i = 0; i < nums2.size(); i++)
        {
            //找到
            if (s.count(nums2[i]))
            {
                //删除nums1中该位置的数
                s.erase(s.find(nums2[i]));
                result.push_back(nums2[i]);
            }
        }
        return result;
    }

    void test()
    {
        std::vector<int> result = intersect(std::vector<int>() = { 1,2,2,1 }, std::vector<int>() = { 2,2,2 });
        for (int i = 0; i < result.size(); i++)
        {
            std::cout << result[i] << ' ';
        }
    }
};