#pragma once

/*
名称：回文链表

描述：给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
     如果是，返回 true ；否则，返回 false 。

解题思路：获取链表中心节点，将后半部分链表进行反转，再将两部分进行回文判断。
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

class LeetCode0234
{
public:
    //快慢指针获取链表中心节点
    ListNode* get_center_node(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    //反转链表
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while (curr)
        {
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
    bool isPalindrome1(ListNode* head)
    {
        ListNode* center_node = get_center_node(head);
        ListNode* second_list_start = reverseList(center_node->next);
        
        ListNode* h1 = head;
        ListNode* h2 = second_list_start;
        //判断两链表是否相同
        while (h2)
        {
            if (h1->val!=h2->val)
            {
                reverseList(second_list_start);
                return false;
            }
            else
            {
                h1 = h1->next;
                h2 = h2->next;
            }
        }
        return true;
    };
    //将值复制到数组中后用双指针法
    bool isPalindrome2(ListNode* head) {
        std::vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--)
        {
            if (nums[i] != nums[j])
            {
                return false;
            }
        }
        return true;
    }

    void test()
    {
        //添加数据
        int nums[] = { 1,1,2,1 };
        ListNode* head = new ListNode(nums[0]);
        std::cout << head->val << ' ';
        ListNode* temp = head;
        for (int i = 1; i < 4; i++)
        {
            temp->next = new ListNode(nums[i]);
            temp = temp->next;
            std::cout << temp->val << ' ';
        }
        std::cout << std::endl;
        std::cout << (isPalindrome1(head) ? "true" : "false");
        std::cout << std::endl;
        std::cout << (isPalindrome2(head) ? "true" : "false");
    }
};