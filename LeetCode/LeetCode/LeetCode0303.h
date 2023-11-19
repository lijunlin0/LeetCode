#pragma once
/*
名称：区域和检索 - 数组不可变

描述：给定一个整数数组  nums，处理以下类型的多个查询:
计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，其中 left <= right
实现 NumArray 类：
NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j) 返回数组 nums 中索引 left 和 right 之间的元素的 总和 ，包含 left 和 right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )

示例 ：
输入：
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
输出：
[null, 1, -1, -3]
解释：
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1))
numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))

解题思路：将前缀和存入一个数组，根据下标进行运算。
*/

#include<iostream>
#include<vector>

class LeetCode0303 {
public:
    //默认构造
    LeetCode0303() 
    {

    }
    //前缀和数组
    std::vector<int> pre_sum;
    LeetCode0303(std::vector<int>& nums) {
        //将数组大小加一用于和nums数组累加
        pre_sum.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }   
    }

    int sumRange(int left, int right) {
        return pre_sum[right + 1] - pre_sum[left];
    }

    void test()
    {
        std::vector<int> nums = { -2,0,3,-5,2,-1 };
        LeetCode0303 L(nums);
        std::cout << L.sumRange(2, 5);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */