#pragma once
/*
名称：环形链表

描述；给你一个链表的头节点 head ，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
如果链表中存在环 ，则返回 true 。 否则，返回 false 。

解题思路：快慢指针：将slow指针指向head，fast指针指向head->next，然后slow指针每次前进一步，fast指针一次前进两步，若链表有环则slow必然会赶上fast。
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