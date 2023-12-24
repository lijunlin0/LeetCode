#pragma once

/*
名称：分发饼干

描述：假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子 i，都有一个胃口值 g[i]，
     这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，
     这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

解题思路：排序+双指针+贪心：将两数组排序，两指针分别指向头部，遍历孩子数组，内存循环中跳过不适合的饼干，判断该位置是否为还有饼干。
*/

#include<iostream>
#include<vector>
#include<queue>

class LeetCode0455 {
public:
    int findContentChildren(std::vector<int>&g, std::vector<int>& s) {
        //排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;

        for (int i = 0, j = 0; i < g.size() && j < s.size(); i++, j++)
        {
            //跳过不适合的饼干
            while (j < s.size() && s[j] < g[i])
            {
                j++;
            }
            //是否符合
            if (j < s.size())
            {
                result++;
            }
        }
        return result;
    }

    void test()
    {
        std::cout << findContentChildren(std::vector<int>() = { 1,2,3 }, std::vector<int>() = { 1,1 });
    }
};