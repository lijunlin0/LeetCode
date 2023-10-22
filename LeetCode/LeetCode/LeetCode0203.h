#pragma once
/*
名称：移除链表元素

描述：给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

解题思路：在头节点前加一个节点方便操作和返回，迭代整个链表，通过当前节点的下一个节点去进行判断和操作。
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
        //在头节点前加一个节点方便返回
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
        //添加数据
        ListNode* head=new ListNode(1);
        ListNode* temp = head;
        int nums[] = {2,6,3,4,5,6 };
        for (int i = 0; i < 6; i++)
        {
            temp->next = new ListNode(nums[i]);
            temp = temp->next;
        }

        //输出传入前数据
        temp = head;
        std::cout << "前：";
        while (temp)
        {
            std::cout<< temp->val << ' ';
            temp = temp->next;
        }
        //输出传入后数据
        temp = removeElements(head, 6);
        std::cout << std::endl<<"后：";
        while (temp)
        {
            std::cout<< temp->val<<' ';
            temp = temp->next;
        }
    }
};