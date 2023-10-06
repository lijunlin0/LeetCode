#pragma once
/*
���ƣ���������

����������һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ���
Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������
��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��

����˼·������ָ�룺��slowָ��ָ��head��fastָ��ָ��head->next��Ȼ��slowָ��ÿ��ǰ��һ����fastָ��һ��ǰ���������������л���slow��Ȼ�����fast��
*/
#include<iostream>

  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class LeetCode0141 {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }

    void test()
    {
        ListNode* head = new ListNode(3);
        head->next=new ListNode(0);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(6);
        head->next->next->next->next = head->next;
        std::cout<<hasCycle(head);
    }
};