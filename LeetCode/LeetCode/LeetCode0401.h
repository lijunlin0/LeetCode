#pragma once

/*
名称：二进制手表

描述：二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。每个 LED 代表一个 0 或 1，最低位在右侧。
     给你一个整数 turnedOn ，表示当前亮着的 LED 的数量，返回二进制手表可以表示的所有可能时间。你可以 按任意顺序 返回答案。
     小时不会以零开头：
     例如，"01:00" 是无效的时间，正确的写法应该是 "1:00" 。
     分钟必须由两位数组成，可能会以零开头：
     例如，"10:2" 是无效的时间，正确的写法应该是 "10:02" 。

解题思路：通过双层循环遍历每小时每分钟并计算 小时和分钟数在二进制中1的个数的和 是否 等于n。
*/

#include<iostream>
#include<vector>
#include <string>
class LeetCode0401 {
public:
    //计算一个数在二进制中的1的数
    int count(int n)
    {
        int res = 0;
        while (n)
        {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> res;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                if (count(i) + count(j) == turnedOn)
                {
                    res.push_back(std::to_string(i) + ":" + (j < 10 ? "0" + std::to_string(j) : std::to_string(j)));
                }
            }
        }
        return res;
    }

    void test()
    {
        std::vector<std::string> res = readBinaryWatch(1);
        for (int i = 0; i < res.size(); i++)
        {
            std::cout << res[i] << ' ';
        }
    }
};