#pragma once
/*
名称：加一

描述：
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

解题思路：从最后一位数开始遍历，如果该数加1等于10（需要进位），则将该位赋值为0，直到遍历的数加1不等于10（不需要进位），则把他加一后返回，若循环结束还未返回则意味着该数组中的值全为9，应该在首部插入一个1后返回。
*/
#include<vector>
#include<iostream>
using namespace std;

class LeetCode0066 {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int temp = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            if (digits[i] + 1 == 10)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }

    void test()
    {
        vector<int> nums = { 9,9,9,9 };
        nums=plusOne(nums);
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << ' ';
        }
    }
};
