#pragma once

/*
���ƣ���������

����������һ��  ���ظ�Ԫ�� �� ���� �������� nums ��
     ���� ǡ�ø����������������� �� ��С���� ���䷶Χ�б� ��Ҳ����˵��nums ��ÿ��Ԫ�ض�ǡ�ñ�ĳ�����䷶Χ�����ǣ����Ҳ���������ĳ����Χ�������� nums ������ x ��
     �б��е�ÿ�����䷶Χ [a,b] Ӧ�ð����¸�ʽ�����
     "a->b" ����� a != b
     "a" ����� a == b

����˼·������˫ָ�룬�������飬���ݵ�λ���ݺͶ�λ���ݽ��в�ͬ�Ĳ�����
*/

#include<iostream>
#include<vector>
#include<string>

class LeetCode0228 {
public:
    std::vector<std::string> s;
    int slow = 0;
    int fast = 1;
    //����ַ���
    void add(int a, int b)
    {
        //��λ
        if (a == b)
        {
            s.push_back(std::to_string(a));
            slow++;
        }
        //��λ
        else
        {
            s.push_back(std::to_string(a) + "->" + std::to_string(b));
            slow = fast;
        }
    }

    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if (nums.size() == 0)
        {
            return s;
        }
        while (fast < nums.size())
        {
            if (nums[fast] != nums[fast - 1] + 1)
            {
                add(nums[slow], nums[fast - 1]);
            }
            fast++;
        }
        //���ĩβԪ��
        add(nums[slow], nums[fast - 1]);
        return s;
    }

    void test()
    {
        std::vector<int> nums = { 0,1,2,4,5,7 };
        std::vector<std::string> strings = summaryRanges(nums);
        for (int i = 0; i < strings.size(); i++)
        {
            std::cout << strings[i] << ',';
        }
    }
};