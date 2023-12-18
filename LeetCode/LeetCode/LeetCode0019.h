#pragma once

/*
名称：删除链表的倒数第 N 个结点

描述：给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

解题思路：创建一个空指针temp指向头节点方便操作，创建快慢指针fast和slow分别指向temp，
         先将fast指针走n+1步，使其fast到达末尾时，fast和slow的距离为n，
         然后fast和slow同时走，当fast为空指针时，将slow->next指向slow->next->next达到删除的效果。
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LeetCode0019 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //空的头指针
        ListNode* temp = new ListNode(0);
        ListNode* fast = temp;
        ListNode* slow = temp;
        temp->next = head;
        for (int i = 0; i < n + 1; i++)
        {
            fast = fast->next;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return temp->next;
    }

    void test()
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        ListNode* temp = removeNthFromEnd(head, 3);
        while (temp)
        {
            std::cout << temp->val << "->";
            temp = temp->next;
        }
    }
};