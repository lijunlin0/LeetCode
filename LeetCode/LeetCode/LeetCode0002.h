#pragma once
/*
����: �������

����:
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

����˼·:

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
