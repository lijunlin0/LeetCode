#pragma once
/*
名称：只出现一次的数字

描述：给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

异或运算性质：1.任何数和 0 做异或运算，结果仍然是原来的数，即 a⊕0=a。
             2.任何数和其自身做异或运算，结果是 0，即 a⊕a=0。
             3.异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b。

解题思路：假设数组中有 2m+1 个数，其中有 m 个数各出现两次，一个数出现一次。
根据上述性质可知，两个相同的数进行异或运算等于0，则将所有相同的数进行异或运算后全为0，最后剩余的那个数便是出现一次的数，
所以将整个数组进行异或运算得到的便是答案。
*/
#include<iostream>
#include<vector>

class LeetCode0136 {
public:
    //异或运算  
    int singleNumber1(std::vector<int>& nums) {
        int ret = 0;
        for (int e = 0; e < nums.size(); e++)
        {
            //进行异或运算
            ret ^= nums[e];
        }
        return ret;
    }
    //暴力循环
    int singleNumber2(std::vector<int>& nums) 
    {   
        for (int i = 0; i < nums.size(); i++)
        {
            bool found = true;
            for (int j = 0; j < nums.size(); j++)
            {
                if (j==i)
                {
                    continue;
                }
                if (nums[j] == nums[i])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                return nums[i];
            }
        }
        return 0;
    }

    void test()
    {
        std::vector<int> nums = { 2,2,1};
        std::cout<<singleNumber1(nums);
    }
};
