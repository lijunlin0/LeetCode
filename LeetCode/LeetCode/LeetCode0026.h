#pragma once
/*
���ƣ�ɾ�����������е��ظ���

������
����һ�� �������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��Ȼ�󷵻� nums ��ΨһԪ�صĸ�����

����˼·��
�����ظ���Ԫ�ؽ���ǰ�ƣ�˫ָ��i��j��jָ���ʾ�������鵽����±�λ�ã�iָ���ʾ��һ����ͬԪ��Ҫ������±�λ�ã���ʼʱ����ָ�붼ָ���±� 1��Ȼ�����������и�ֵ
*/
#include<iostream>
#include<vector>
using namespace std;

class LeetCode0026{
public:
    //˫ָ�루�Ž⣩
    int removeDuplicates1(vector<int>& nums) {
        int i = 1;
        int j = 1;
        for (; j <= nums.size() - 1; j++)
        {
            //������������
            if (nums[i-1] != nums[j])
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
    //����������ʱ�䣩
    int removeDuplicates2(vector<int>& nums) {
        for (vector<int>::iterator it = nums.begin()+1; it != nums.end();)
        {
            if (*it == *(it - 1))
            {
                it = nums.erase(it);
            }
            else
            {
                it++;
            }
        }
        return nums.size();
    }
    
    void test()
    {
        vector<int> nums = {1,1,1, 2,2,3,4 };
        cout<<"size:"<<removeDuplicates1(nums);
    }
};
