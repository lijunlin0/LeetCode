#pragma once

/*
名称：盛最多水的容器

描述：给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
     找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。返回容器可以储存的最大水量。说明：你不能倾斜容器。

解题思路：双指针，面积由短板决定S(i,j)=min(h[i],h[j])×(j−i)；不断将短板指针向中间移动，使其出现更大的面积。    
*/

#include<iostream>
#include<vector>

class LeetCode0011 {
public:
    int maxArea(std::vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;
        while (i < j)
        {
            int area = std::min(height[i], height[j]) * (j - i);
            max_area = std::max(max_area, area);
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return max_area;
    }

    void test()
    {
        std::vector<int> height = { 1,8,6,2,5,4,8,3,7 };
        std::cout<<maxArea(height);
    }
};