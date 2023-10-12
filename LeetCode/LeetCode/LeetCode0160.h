#pragma once

/*
���ƣ��ཻ����

���������������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
ͼʾ���������ڽڵ� c1 ��ʼ�ཻ��
��Ŀ���� ��֤ ������ʽ�ṹ�в����ڻ���
ע�⣬�������ؽ����������� ������ԭʼ�ṹ ��

����˼·��
1.��ϣ����������A������ÿ���ڵ�����ϣ���У�Ȼ�����B�����ж��Ƿ����ཻ�ڵ㡣
2.˫ָ�룺������ָ��ֱ�ָ��ͷ�ڵ㣬Ȼ�������ʱ����������һ������ʹ������Ľڵ�����ͬ��ʹ���Ƕ��룬
         �����ཻ�򷵻ؽڵ㣬�����ཻ���ͬʱ������nullptr��
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
    //˫ָ��
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
    //��ϣ����
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