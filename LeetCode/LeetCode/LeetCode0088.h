#pragma once
/*
���ƣ��ϲ�������������

������
���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n��
����ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��

����˼·������˫ָ�룺������ָ��ָ����������ĩβ������������ϴ�ֵ����nums1ĩβ�Ķ���λ�á����ŵ㣺����Ҫʹ�ö���ռ䣩
*/
#include<iostream>
#include<vector>
#include<algorithm>

class LeetCode0088
{
public:
    //����˫ָ�루�Ž⣩
    void merge1(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        while (p1 >= 0 || p2 >= 0)
        {
            if (p1 == -1) 
            {
                nums1[tail--] = nums2[p2--];
            }
            else if (p2 == -1) 
            {
                nums1[tail--] = nums1[p1--];
            }
            else if (nums1[p1] > nums2[p2]) 
            {
                nums1[tail--] = nums1[p1--];
            }
            else 
            {
                nums1[tail--] = nums2[p2--];
            }
        }
    }

    //ֱ�Ӻϲ�������
    void merge2(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }

    void test()
    {
        std::vector<int> nums1 = { 1,3,5,7,9,0,0,0,0,0};
        std::vector<int> nums2 = { 2,4,6,8,10 };
        merge1(nums1, 5, nums2, nums2.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            std::cout << nums1[i]<<' ';
        }
    }
};
