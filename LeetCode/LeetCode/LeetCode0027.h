#pragma once
/*
���ƣ��Ƴ�Ԫ��

������
����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

����˼·��
˫ָ�룺���Ƚ�����ָ��ָ���ײ���i���ڸ�ֵ��j���ڲ��ң�j��ͣ��ǰ��������nums[j]==val�ĵط���ֱ��nums[j]!=val�ͽ��丳ֵ��nums[i],Ȼ��iǰ����
˫ָ���Ż�����i�����������ײ���j�������������һλ�ĺ��棬���nums[i]!=val��iǰ����������j-1λ�õ�Ԫ�ظ�ֵ��iλ�ã�Ȼ��j�����ơ�
�Ż�����ŵ㣺����ָ�����������¼�����ֻ����������һ�Σ���δ�Ż���˫ָ�벻ͬ���ǣ��Ż����������Ҫ������Ԫ�ص��ظ���ֵ������
*/
#include<iostream>
#include<vector>
using namespace std;

class LeetCode0027
{
public:
	//˫ָ���Ż�
	int removeElement1(vector<int>& nums, int val)
	{
		int i = 0;
		int j = nums.size();
		while (i<j)
		{
			if (nums[i] == val)
			{
				nums[i] = nums[j-1];
				j--;
			}
			else
			{
				i++;
			}
		}
		return i;
	}
	//˫ָ��
	int removeElement2(vector<int>& nums, int val) {
		int i = 0;
		int j = 0;
		for (; j < nums.size(); j++)
		{
			if (nums[j] != val)
			{
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
	void test()
	{
		vector<int> nums = { 3,2,2,3 };
		cout<<removeElement1(nums, 3);
	}
};
