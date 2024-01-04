#pragma once

/*
���ƣ�������ܳ�

����������һ�� row x col �Ķ�ά�����ͼ grid �����У�grid[i][j] = 1 ��ʾ½�أ� grid[i][j] = 0 ��ʾˮ��
     �����еĸ��� ˮƽ�ʹ�ֱ �����������Խ��߷�������������������ˮ��ȫ��Χ��������ǡ����һ�����죨����˵��һ��������ʾ½�صĸ���������ɵĵ��죩��
     ������û�С������������� ָˮ���ڵ����ڲ��Ҳ��͵�����Χ��ˮ�������������Ǳ߳�Ϊ 1 �������Ρ�����Ϊ�����Σ��ҿ�Ⱥ͸߶Ⱦ������� 100 ���������������ܳ���

����˼·��������ά�����ÿһ��½�أ������ǰ����Ϊ½�� ��ǰ���ӵ��ܳ�Ϊ4���ж���Χ�ĸ����ӣ���һ��������½����ǰ�����ܳ���һ��
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
                //��ǰ����Ϊ½��
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