#pragma once

/*
名称：反转链表

描述：给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

解题思路：声明一个节点保存上一个节点，直接将当前节点的next指针指向上一个节点。
*/

#include<iostream>
#include<vector>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LeetCode0206 {
public:
    //直接将当前节点的next指针指向上一个节点
    ListNode* reverseList1(ListNode* head)
    {
        ListNode* pre=nullptr;
        while (head)
        {
            ListNode* temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
    //将数据存进数组后生成新链表
    ListNode* reverseList2(ListNode* head) {
        std::vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        ListNode* temp = new ListNode();
        ListNode* run = temp;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            run->val = nums[i];
            if (i != 0)
            {
                run = run->next = new ListNode();
            }
        }
        return temp;
    }

    void test()
    {
        //添加数据
        ListNode* head = new ListNode(1);
        std::cout << head->val << ' ';
        int nums[] = { 2,3,4,5 };
        ListNode* temp = head;
        for (int i = 0; i < 4; i++)
        {
            temp->next = new ListNode(nums[i]);
            temp = temp->next;
            std::cout << temp->val << ' ';
        }
        std::cout << std::endl;
        head=reverseList1(head);
        while (head)
        {
            std::cout << head->val << ' ';
            head = head->next;
        }
    }
};
