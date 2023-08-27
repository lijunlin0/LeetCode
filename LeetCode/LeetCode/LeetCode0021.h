#pragma once
/*
���ƣ��ϲ�������������

������
��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

����˼·��
 �Ƚ����������ֵ��ѡ���Сֵ��������
*/
#include<math.h>
#include<iostream>
using namespace std;
struct listnode
{
    int val;
    listnode* next;
    listnode() : val(0), next(nullptr) {}
    listnode(int x) : val(x), next(nullptr) {}
    listnode(int x, listnode* next) : val(x), next(next) {}
};
 
class LeetCode0021 {
public:
    listnode* mergeTwoLists(listnode* list1, listnode* list2) 
    {
        listnode* temp = new listnode();
        listnode* head = temp;
        int i = 0;
        while (true)
        {
            //�������1�����꣬������2ʣ���Ԫ�������ڴ𰸺�
            if (list1== nullptr)
            {
                temp ->next= list2;
                temp = temp->next;
                return head->next;
            }
            //�������2�����꣬������1ʣ���Ԫ�������ڴ𰸺�
            else if (list2 == nullptr)
            {
                temp->next = list1;
                temp = temp->next;             
                return head->next;
            }
            if (list1->val < list2->val)
            {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
            i++;
        }
    }

    void test()
    {
        listnode* l1 = new listnode(1);
        l1->next = new listnode(5);
        l1->next->next = new listnode(7);
        l1->next->next->next= new listnode(9);

        listnode* l2 = new listnode(2);
        l2->next = new listnode(8);
        l2->next->next = new listnode(9);
        l1 = mergeTwoLists(l1, l2);
        while (l1 != nullptr)
        {
            cout << l1->val << ' ';
            l1 = l1->next;
        }
    }
};
