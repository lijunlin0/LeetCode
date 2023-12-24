#pragma once

/*
���ƣ��������������еĽڵ�

����������һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������

����˼·�����������洢���ݣ��ٽ�����
*/

#include<iostream>

  
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LeetCode0024 {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head)
        {
            return head;
        }
        //��ͷ�ڵ�
        ListNode* res = new ListNode(0);
        res->next = head;
        while (head && head->next)
        {
            //�洢��ǰ���� ���ڽ���
            int temp = head->val;
            //����
            head->val = head->next->val;
            head = head->next;
            head->val = temp;
            //ǰ��
            head = head->next;
        }
        return res->next;
    }

    void test()
    {
        ListNode* head = new ListNode(1);
        head->next= new ListNode(2);
        head->next->next = new ListNode(3);
       head->next->next->next = new ListNode(4);
        ListNode* res = swapPairs(head);
        while (res)
        {
            std::cout << res->val;
            if (res->next)
            {
                std::cout <<"->";
            }
            res = res->next;
        }
    }
};