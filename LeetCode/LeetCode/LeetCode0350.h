#pragma once

#include<iostream>
#include<vector>
#include <set>

/*
���ƣ���������Ľ��� II

���������������������� nums1 �� nums2 ��������������ʽ����������Ľ��������ؽ����ÿ��Ԫ�س��ֵĴ�����
     Ӧ��Ԫ�������������ж����ֵĴ���һ�£�������ִ�����һ�£�����ȡ��Сֵ�������Բ�������������˳��

����˼·����nums1����multiset�����Դ��ظ�Ԫ�أ��У�����nums2����multiset�е�nums1�Ƚ��Ƿ��н��������ҵ�������multiset��ɾ����λ���ϵ�����
*/

class LeetCode0350 {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::multiset<int> s(nums1.begin(), nums1.end());
        std::vector<int> result;
        for (int i = 0; i < nums2.size(); i++)
        {
            //�ҵ�
            if (s.count(nums2[i]))
            {
                //ɾ��nums1�и�λ�õ���
                s.erase(s.find(nums2[i]));
                result.push_back(nums2[i]);
            }
        }
        return result;
    }

    void test()
    {
        std::vector<int> result = intersect(std::vector<int>() = { 1,2,2,1 }, std::vector<int>() = { 2,2,2 });
        for (int i = 0; i < result.size(); i++)
        {
            std::cout << result[i] << ' ';
        }
    }
};