#pragma once

/*
名称：相交链表

描述：给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
图示两个链表在节点 c1 开始相交：
题目数据 保证 整个链式结构中不存在环。
注意，函数返回结果后，链表必须 保持其原始结构 。

解题思路：
1.哈希容器：遍历A链表并将每个节点存进哈希表中，然后遍历B链表判断是否有相交节点。
2.双指针：用两个指针分别指向头节点，然后遍历完时继续遍历另一个链表，使其遍历的节点数相同，使他们对齐，
         若有相交则返回节点，若不相交则会同时遍历到nullptr。
*/

#include<iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LeetCode0160 {
public:
    //双指针
    ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode* i = headA;
        ListNode* j = headB;
        while (i != j)
        {
            i = i == nullptr ? headB : i->next;
            j = j == nullptr ? headA : j->next;
        }
        return i;
    }
    //哈希容器
    ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB) {
        std::unordered_set<ListNode*> temp;
        while (headA != nullptr)
        {
            temp.insert(headA);
            headA = headA->next;
        }
        while (headB != nullptr)
        {
            if (temp.count(headB))
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
    void test()
    {
        ListNode* headA = new ListNode(5);
        headA->next = new ListNode(6);
        headA->next->next = new ListNode(1);
        headA->next->next->next = new ListNode(8);
        headA->next->next->next->next = new ListNode(4);
        headA->next->next->next->next->next = new ListNode(5);
        ListNode* headB = new ListNode(4);
        headB->next = new ListNode(1);
        headB->next->next = headA->next->next->next;
        std::cout<<getIntersectionNode1(headA, headB)->val;

    }
};