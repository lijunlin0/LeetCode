#pragma once
/*
名称：删除有序数组中的重复项

描述：
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

解题思路：
将不重复的元素进行前移，双指针i，j；j指针表示遍历数组到达的下标位置，i指针表示下一个不同元素要填入的下标位置，初始时两个指针都指向下标 1。然后遍历数组进行赋值
*/
#include<iostream>
#include<vector>
using namespace std;

class LeetCode0026{
public:
    //双指针（优解）
    int removeDuplicates1(vector<int>& nums) {
        int i = 1;
        int j = 1;
        for (; j <= nums.size() - 1; j++)
        {
            //如果整数不相等
            if (nums[i-1] != nums[j])
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
    //迭代器（耗时间）
    int removeDuplicates2(vector<int>& nums) {
        for (vector<int>::iterator it = nums.begin()+1; it != nums.end();)
        {
            if (*it == *(it - 1))
            {
                it = nums.erase(it);
            }
            else
            {
                it++;
            }
        }
        return nums.size();
    }
    
    void test()
    {
        vector<int> nums = {1,1,1, 2,2,3,4 };
        cout<<"size:"<<removeDuplicates1(nums);
    }
};
