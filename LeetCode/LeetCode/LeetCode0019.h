#pragma once

/*
���ƣ�ɾ������ĵ����� N �����

����������һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣

����˼·������һ����ָ��tempָ��ͷ�ڵ㷽���������������ָ��fast��slow�ֱ�ָ��temp��
         �Ƚ�fastָ����n+1����ʹ��fast����ĩβʱ��fast��slow�ľ���Ϊn��
         Ȼ��fast��slowͬʱ�ߣ���fastΪ��ָ��ʱ����slow->nextָ��slow->next->next�ﵽɾ����Ч����
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

        //�յ�ͷָ��
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