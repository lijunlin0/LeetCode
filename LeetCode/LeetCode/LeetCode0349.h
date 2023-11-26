#pragma once

/*
���ƣ���������Ľ���

���������������������� nums1 �� nums2 ������ ���ǵĽ��� ��
      �������е�ÿ��Ԫ��һ���� Ψһ �ġ����ǿ��� ��������������˳��

����˼·������һ�����Ͻ�nums1���ȥ��ѭ������nums2������ҵ���ͬ��������������У����ڼ�����ɾ����Ԫ����������ظ�Ԫ�ء�
*/

#include<unordered_set>
#include<vector>
#include<iostream>

class LeetCode0349
{
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> s(nums1.begin(), nums1.end());
        std::vector<int> result;
        for (int i = 0; i < nums2.size(); i++)
        {
            //�ҵ�
            if (s.find(nums2[i]) != s.end())
            {
                result.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }
        return result;
    }

    void test()
    {
        std::vector<int> result = intersection(std::vector<int>() = { 4,9,5 }, std::vector<int>() = { 9,4,9,8,4 });
        for (int i = 0; i < result.size(); i++)
        {
            std::cout << result[i] << ' ';
        }
    }

};