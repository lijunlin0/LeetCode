#pragma once
/*
名称: 两数相加

描述:
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

解题思路:

*/
#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class LeetCode0002 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; l1 != nullptr; i++)
        {
            num1 = num1 * 10 + l1->val;
            l1 = l1->next;
        }
        for (int i = 0; l2 != nullptr; i++)
        {
            num2 = num2 * 10 + l2->val;
            l2 = l2->next;
        }
        int size = 0;
        int sum = num1 + num2;
        int sum2 = sum;
        while (sum2>0)
        {
            sum2 /= 10;
            size++;
        }
        ListNode* temp=new ListNode();
        ListNode* head = temp;
        int size2 = size;
        for (int i = 0; i < size; i++)
        {
            temp->val = sum % 10;
            sum /= 10;
            if (i < size - 1)
            {
                temp->next = new ListNode();
                temp = temp->next;
            }
        }
        return head;
    }
    void test()
    {
        ListNode* l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(9);
        ListNode* l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);
        l2->next->next->next = new ListNode(9);
        ListNode* sum = addTwoNumbers(l1, l2);
        cout << sum->val << ' ' << sum->next->val << ' ' << sum->next->next->val << ' ' << sum->next->next->next->val << endl;

    }
};
