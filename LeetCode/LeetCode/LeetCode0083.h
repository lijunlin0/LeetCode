#pragma once

/*
���ƣ�ɾ�����������е��ظ�Ԫ��

����������һ��������������ͷ head �� ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�� ������ ����������� ��

����˼·���������������ǰ�ڵ��ֵ������һ���ڵ��ֵ�򽫵�ǰ�ڵ�ָ����һ���ڵ����һ���ڵ㡣
*/

#include<iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LeetCode0083
{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }
        ListNode* i = head;
        while (i->next != nullptr)
        {
            if (i->val == i->next->val)
            {
                i->next = i->next->next;
            }
            else
            {
                i = i->next;
            }
        }
        return head;
    }
    void test()
    {
        ListNode* L = new ListNode(1);
        L->next = new ListNode(1);
        L->next->next = new ListNode(2);
        L->next->next->next = new ListNode(3);
        L->next->next->next->next = new ListNode(3);
        deleteDuplicates(L);
        std::cout << L->val << " " << L->next->val << " " << L->next->next->val << " ";
    }
};