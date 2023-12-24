#pragma once

/*
名称：两两交换链表中的节点

描述：给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

解题思路：遍历链表，存储数据，再交换。
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
        //空头节点
        ListNode* res = new ListNode(0);
        res->next = head;
        while (head && head->next)
        {
            //存储当前数据 用于交换
            int temp = head->val;
            //交换
            head->val = head->next->val;
            head = head->next;
            head->val = temp;
            //前进
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