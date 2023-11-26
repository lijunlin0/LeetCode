#pragma once

/*
名称：两个数组的交集

描述：描述给定两个数组 nums1 和 nums2 ，返回 它们的交集 。
      输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序

解题思路：创建一个集合将nums1存进去，循环遍历nums2，如果找到相同的则将其存入数组中，并在集合中删除此元素以免存入重复元素。
*/

#include<unordered_set>
#include<vector>
#include<iostream>

class LeetCode0349
{
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> s(nums1.begin(), nums1.end());
        std::vector<int> result;
        for (int i = 0; i < nums2.size(); i++)
        {
            //找到
            if (s.find(nums2[i]) != s.end())
            {
                result.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }
        return result;
    }

    void test()
    {
        std::vector<int> result = intersection(std::vector<int>() = { 4,9,5 }, std::vector<int>() = { 9,4,9,8,4 });
        for (int i = 0; i < result.size(); i++)
        {
            std::cout << result[i] << ' ';
        }
    }

};