#pragma once

/*
���ƣ��ҵ�������������ʧ������

����������һ���� n ������������ nums ������ nums[i] ������ [1, n] �ڡ������ҳ������� [1, n] ��Χ�ڵ�û�г����� nums �е����֣������������ʽ���ؽ����

����˼·�������������ִ����ϣ���ٱ���1��n���ҡ�
*/

#include<iostream>
#include<vector>
#include <queue>
#include<unordered_set>

class LeetCode0448 {
public:

    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::vector<int> result;
        std::unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.emplace(nums[i]);
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            if (!s.count(i))
            {
                result.push_back(i);
            }
        }
        return result;
    }


    void test()
    {
        std::vector<int> result = findDisappearedNumbers(std::vector<int>() = { 1,2 });
        for (int i = 0; i < result.size(); i++)
        {
            std::cout << result[i] << ',';
        }
    }
};