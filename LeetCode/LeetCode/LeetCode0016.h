#pragma once

/*
���ƣ���ӽ�������֮��

����������һ������Ϊ n ���������� nums �� һ��Ŀ��ֵ target������� nums ��ѡ������������
     ʹ���ǵĺ��� target ��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����ǡ��һ���⡣

����˼·��1.�������������
         2.�������飺
         (1)�� sum==target��ֱ�ӷ���sum;
         (2)��sum<target:���ж���target�ľ����Ƿ��С������С����²������ظ�Ԫ��;
         (3)��sum>target:���ж���target�ľ����Ƿ��С������С����²������ظ�Ԫ��;
         3.��ѭ����û�з������ʾû���������ĺ͵���target�򷵻�target+����(gap);
*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class LeetCode0016 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int gap = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int L = i + 1;
            int R = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            while (L < R)
            {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == target)
                {
                    return sum;
                }
                if (sum < target)
                {
                    if (abs(sum - target) < abs(gap))
                    {
                        gap = -abs(sum - target);
                    }
                    while (L < R && nums[L] == nums[L + 1])
                    {
                        L++;
                    }
                    L++;
                }
                else
                {
                    if (abs(sum - target) < abs(gap))
                    {
                        gap = abs(sum - target);
                    }
                    while (L < R && nums[R] == nums[R - 1])
                    {
                        R--;
                    }
                    R--;
                }
            }
        }
        return target + gap;
    }

    void test()
    {
        std::cout<<threeSumClosest(std::vector<int>() = { 2,3,8,9,10 }, 16);
    }
};
