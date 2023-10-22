#pragma once
/*
���ƣ��Ƴ�����Ԫ��

����������һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��

����˼·����ͷ�ڵ�ǰ��һ���ڵ㷽������ͷ��أ�������������ͨ����ǰ�ڵ����һ���ڵ�ȥ�����жϺͲ�����
*/
#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LeetCode0203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //��ͷ�ڵ�ǰ��һ���ڵ㷽�㷵��
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* i = dummyHead;
        while (i->next)
        {
            if (i->next->val == val)
            {
                i->next = i->next->next;
            }
            else
            {
                i = i->next;
            }
        }
        return dummyHead->next;
    }
    void test()
    {
        //�������
        ListNode* head=new ListNode(1);
        ListNode* temp = head;
        int nums[] = {2,6,3,4,5,6 };
        for (int i = 0; i < 6; i++)
        {
            temp->next = new ListNode(nums[i]);
            temp = temp->next;
        }

        //�������ǰ����
        temp = head;
        std::cout << "ǰ��";
        while (temp)
        {
            std::cout<< temp->val << ' ';
            temp = temp->next;
        }
        //������������
        temp = removeElements(head, 6);
        std::cout << std::endl<<"��";
        while (temp)
        {
            std::cout<< temp->val<<' ';
            temp = temp->next;
        }
    }
};