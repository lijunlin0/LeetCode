#pragma once

/*
名称：汇总区间

描述：给定一个  无重复元素 的 有序 整数数组 nums 。
     返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。
     列表中的每个区间范围 [a,b] 应该按如下格式输出：
     "a->b" ，如果 a != b
     "a" ，如果 a == b

解题思路：快慢双指针，遍历数组，根据单位数据和多位数据进行不同的操作。
*/

#include<iostream>
#include<vector>
#include<string>

class LeetCode0228 {
public:
    std::vector<std::string> s;
    int slow = 0;
    int fast = 1;
    //添加字符串
    void add(int a, int b)
    {
        //单位
        if (a == b)
        {
            s.push_back(std::to_string(a));
            slow++;
        }
        //多位
        else
        {
            s.push_back(std::to_string(a) + "->" + std::to_string(b));
            slow = fast;
        }
    }

    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if (nums.size() == 0)
        {
            return s;
        }
        while (fast < nums.size())
        {
            if (nums[fast] != nums[fast - 1] + 1)
            {
                add(nums[slow], nums[fast - 1]);
            }
            fast++;
        }
        //添加末尾元素
        add(nums[slow], nums[fast - 1]);
        return s;
    }

    void test()
    {
        std::vector<int> nums = { 0,1,2,4,5,7 };
        std::vector<std::string> strings = summaryRanges(nums);
        for (int i = 0; i < strings.size(); i++)
        {
            std::cout << strings[i] << ',';
        }
    }
};