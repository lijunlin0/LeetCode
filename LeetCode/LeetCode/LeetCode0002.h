#pragma once
/*
名称: 两数相加

描述:
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

解题思路:输入的两个链表都是逆序存储数字的位数的，因此两个链表中同一位置的数字可以直接相加。
        逐位计算他们的值，并记录进位值。计算完时若进位值大于0则需额外添加一个节点。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        //进位值
        int carry = 0;
        while (l1 || l2)
        {
            //如果有一个链表遍历完则补0
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;

            int sum = n1 + n2 + carry;
            //第一个节点，用于返回结果
            if (!head)
            {
                head = tail = new ListNode(sum % 10);
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            //求出进位值
            carry = sum / 10;

            //向后遍历
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        //最后两个数相加需要进位数需添加一个节点
        if (carry > 0)
        {
            tail->next = new ListNode(carry);
        }
        return head;
    }
    void test()
    {
        //942+465=1407
        ListNode* l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(9);
        ListNode* l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);
        ListNode* sum = addTwoNumbers(l1, l2);
        cout << sum->val << ' ' << sum->next->val << ' ' << sum->next->next->val << ' ' << sum->next->next->next->val << endl;
    }
};
