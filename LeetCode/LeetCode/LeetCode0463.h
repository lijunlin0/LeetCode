#pragma once

/*
名称：岛屿的周长

描述：给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
     网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
     岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

解题思路：遍历二维网格的每一格陆地，如果当前格子为陆地 则当前格子的周长为4，判断周围四个格子，有一个格子是陆地则当前格子周长减一。
*/


#include<iostream>
#include<vector>

class LeetCode0463 {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                //当前格子为陆地
                if (grid[i][j] == 1)
                {
                    int temp = 4;
                    if (i - 1 >= 0 && grid[i - 1][j] == 1)
                    {
                        temp--;
                    }
                    if (i + 1 < grid.size() && grid[i + 1][j] == 1)
                    {
                        temp--;
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 1)
                    {
                        temp--;
                    }
                    if (j + 1 < grid[i].size() && grid[i][j + 1] == 1)
                    {
                        temp--;
                    }
                    result += temp;
                }
            }
        }
        return result;
    }

    void test()
    {
        std::vector<std::vector<int>> res;
        std::vector<int> a = { 0,1,0,0 };
        std::vector<int> b = { 1,1,1,0 };
        std::vector<int> c = { 0,1,0,0 };
        std::vector<int> d = { 1,1,0,0 };
        res.push_back(a);
        res.push_back(b);
        res.push_back(c);
        res.push_back(d);
        std::cout << islandPerimeter(res);
    }
};