#pragma once

/*
���ƣ���������

����������һ���������ͷ�ڵ� head �������жϸ������Ƿ�Ϊ��������
     ����ǣ����� true �����򣬷��� false ��

����˼·����ȡ�������Ľڵ㣬����벿��������з�ת���ٽ������ֽ��л����жϡ�
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
    //����ָ���ȡ�������Ľڵ�
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
    //��ת����
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
        //�ж��������Ƿ���ͬ
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
    //��ֵ���Ƶ������к���˫ָ�뷨
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
        //�������
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