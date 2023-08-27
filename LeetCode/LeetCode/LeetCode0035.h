#pragma once
/*
���ƣ���������λ��

����������һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�---�������ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨����

����˼·��
���ֲ��ң�����lΪ�����ײ���rΪ����β����ÿ�β��Ҷ���һ��midλ�������м䣬Ȼ�����Ŀ��ֵ��mid�±�ֵ�ȽϽ���l��r�ĸ��¡�
*/
#include<iostream>
#include<vector>
using namespace std;

class LeetCode0035
{
public:
    //���ֲ���
    int searchInsert1(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
    //��������������ĿҪ��
	int searchInsert2(vector<int>& nums, int target)
	{
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums[i] >= target)
			{
				return i;
			}
		}
		return n;
	}
    
	void test()
	{
		vector<int>nums = {1};
		cout << searchInsert1(nums, 2);
	}
};
