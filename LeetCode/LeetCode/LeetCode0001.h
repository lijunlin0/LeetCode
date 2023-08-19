#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
名称: 两数之和

描述:

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

解题思路:
使用哈希表:遍历数组中每个整数，并查询（目标值-当前值）是否在哈希表中，如果没有就将当前值存进哈希表，如果找到则返回两个值的下标。
*/
class LeetCode0001 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int>::iterator it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
            {
                return vector<int>{it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return vector<int>{};
    }

    void test()
    {
        vector<int> nums;
        nums.push_back(5);
        nums.push_back(7);
        nums.push_back(2);
        nums.push_back(1);
        nums.push_back(8);
        nums.push_back(0);
        vector<int> temp = twoSum(nums, 3);
        cout << temp[0] << ' ' << temp[1] << endl;
    }
};