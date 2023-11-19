#pragma once
/*
���ƣ�����ͼ��� - ���鲻�ɱ�

����������һ����������  nums�������������͵Ķ����ѯ:
�������� left �� right ������ left �� right��֮��� nums Ԫ�ص� �� ������ left <= right
ʵ�� NumArray �ࣺ
NumArray(int[] nums) ʹ������ nums ��ʼ������
int sumRange(int i, int j) �������� nums ������ left �� right ֮���Ԫ�ص� �ܺ� ������ left �� right ���㣨Ҳ���� nums[left] + nums[left + 1] + ... + nums[right] )

ʾ�� ��
���룺
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
�����
[null, 1, -1, -3]
���ͣ�
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1))
numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))

����˼·����ǰ׺�ʹ���һ�����飬�����±�������㡣
*/

#include<iostream>
#include<vector>

class LeetCode0303 {
public:
    //Ĭ�Ϲ���
    LeetCode0303() 
    {

    }
    //ǰ׺������
    std::vector<int> pre_sum;
    LeetCode0303(std::vector<int>& nums) {
        //�������С��һ���ں�nums�����ۼ�
        pre_sum.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }   
    }

    int sumRange(int left, int right) {
        return pre_sum[right + 1] - pre_sum[left];
    }

    void test()
    {
        std::vector<int> nums = { -2,0,3,-5,2,-1 };
        LeetCode0303 L(nums);
        std::cout << L.sumRange(2, 5);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */