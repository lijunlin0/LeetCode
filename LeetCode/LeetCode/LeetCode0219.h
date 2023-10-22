#pragma once

/*
���ƣ������ظ�Ԫ�� II

����������һ���������� nums ��һ������ k ���ж��������Ƿ�������� ��ͬ������ i �� j ������ nums[i] == nums[j] �� abs(i - j) <= k ��������ڣ����� true �����򣬷��� false ��

����˼·���������飬����ϣ�����ҵ���������abs(i-j)<=k�Ļ���ֱ�ӷ���true����֮���������±괫���ϣ���С�
ע�⣺��������Ӧ������������ �ظ�key�ļ�ֵ�� �滻 ǰ��ļ�ֵ�ԣ�Ӧ��[ ]��Ӽ�ֵ�ԡ�
*/

#include<iostream>
#include<vector>
#include<unordered_map>

class LeetCode0219 {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.count(nums[i]) && std::abs(umap.at(nums[i]) - i) <= k)
            {
                return true;
            }
            else
            {
                umap[nums[i]] = i;
            }
        }
        return false;
    }

    void test()
    {
        std::vector<int> nums = { 1,0,1,1 };
        std::cout<<containsNearbyDuplicate(nums, 1);
    }
};
