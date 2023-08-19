#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
����: ����֮��

����:

����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
����԰�����˳�򷵻ش𰸡�

����˼·:
ʹ�ù�ϣ��:����������ÿ������������ѯ��Ŀ��ֵ-��ǰֵ���Ƿ��ڹ�ϣ���У����û�оͽ���ǰֵ�����ϣ������ҵ��򷵻�����ֵ���±ꡣ
*/
class LeetCode0001 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int>::iterator it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
            {
                return vector<int>{it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return vector<int>{};
    }

    void test()
    {
        vector<int> nums;
        nums.push_back(5);
        nums.push_back(7);
        nums.push_back(2);
        nums.push_back(1);
        nums.push_back(8);
        nums.push_back(0);
        vector<int> temp = twoSum(nums, 3);
        cout << temp[0] << ' ' << temp[1] << endl;
    }
};