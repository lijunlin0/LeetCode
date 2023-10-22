#pragma once

/*
名称：存在重复元素 II

描述：给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

解题思路：遍历数组，若哈希表中找到此数并且abs(i-j)<=k的话则直接返回true，反之将此数和下标传入哈希表中。
注意：此题我们应将后面遇到的 重复key的键值对 替换 前面的键值对，应用[ ]添加键值对。
*/

#include<iostream>
#include<vector>
#include<unordered_map>

class LeetCode0219 {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.count(nums[i]) && std::abs(umap.at(nums[i]) - i) <= k)
            {
                return true;
            }
            else
            {
                umap[nums[i]] = i;
            }
        }
        return false;
    }

    void test()
    {
        std::vector<int> nums = { 1,0,1,1 };
        std::cout<<containsNearbyDuplicate(nums, 1);
    }
};
