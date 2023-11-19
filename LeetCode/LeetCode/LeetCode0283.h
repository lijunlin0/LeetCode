#pragma once

/*
名称：移动零

描述：给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
      请注意 ，必须在不复制数组的情况下原地对数组进行操作。

解题思路：两次遍历：第一次遍历将非零数字左移并记录其0的数量，第二次遍历在结尾赋值记录到的个数的0。
         一次遍历：在遍历途中不停将i，j指针经行交换达到移动0的效果。
         通过两个指针能巧妙地将j指针指向0，i指针指向非零元素。
*/

#include<iostream>
#include<vector>

class LeetCode0283 {
public:
    //一次遍历
    void moveZeroes1(std::vector<int>& nums) {
        int i = 0;
        int j = 0;
        for (; i < nums.size(); i++)
        {
            //交换非零元素
            if (nums[i] != 0)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }
    }

    //两次遍历
    void moveZeroes2(std::vector<int>&nums) {
        int i = 0;
        int j = 0;
        //非零元素左移
        for (; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }
        //赋值0
        for (; j < nums.size(); j++)
        {
            nums[j] = 0;
        }
    }

    void test()
    {
        std::vector<int> nums = { 1,1,0,3,12 };
        moveZeroes1(nums);
        for (int i = 0; i < nums.size(); i++)
        {
            std::cout << nums[i] << ',';
        }
    }
};