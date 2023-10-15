#pragma once
/*
名称：多数元素

描述：给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

解题思路：遍历数组将元素放入哈希表，经过比较获得最大值。
*/

#include<iostream>
#include<unordered_map>

class LeetCode0169
{
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        //较大值
        int majority = 0;
        //较大值个数
        int temp = 0;
        for (auto i : nums)
        {
            //放入表中，并将值加一
            m[i]++;
            if (m[i] > temp)
            {
                majority = i;
                temp = m[i];
            }
        }
        return majority;
    }

    void test()
    {
        std::vector<int> nums = { 3,2,2,2,3 };
        std::cout << majorityElement(nums);
    }
};