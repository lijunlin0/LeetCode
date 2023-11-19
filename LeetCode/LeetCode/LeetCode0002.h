#pragma once
/*
����: �������

����:
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

����˼·:�������������������洢���ֵ�λ���ģ��������������ͬһλ�õ����ֿ���ֱ����ӡ�
        ��λ�������ǵ�ֵ������¼��λֵ��������ʱ����λֵ����0����������һ���ڵ㡣
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
        //��λֵ
        int carry = 0;
        while (l1 || l2)
        {
            //�����һ�������������0
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;

            int sum = n1 + n2 + carry;
            //��һ���ڵ㣬���ڷ��ؽ��
            if (!head)
            {
                head = tail = new ListNode(sum % 10);
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            //�����λֵ
            carry = sum / 10;

            //������
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        //��������������Ҫ��λ�������һ���ڵ�
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
