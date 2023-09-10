#pragma once

/*
名称：删除排序链表中的重复元素

描述：给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。

解题思路：遍历链表，如果当前节点的值等于下一个节点的值则将当前节点指向下一个节点的下一个节点。
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