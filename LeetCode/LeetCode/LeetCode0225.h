#pragma once

/*
���ƣ��ö���ʵ��ջ

�����������ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����

     ʵ�� MyStack �ࣺ
     void push(int x) ��Ԫ�� x ѹ��ջ����
     int pop() �Ƴ�������ջ��Ԫ�ء�
     int top() ����ջ��Ԫ�ء�
     boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��

����˼·����Ҫʵ��push()����Ҫ��ջ����������У�Ȼ����ǰ�����ȫ���ٴ�������У�����ǰ�����ȫ���Ƴ����У������ͽ�����˳��������Խ���pop()������
*/

#include<iostream>
#include<queue>

class LeetCode0225 {
public:
    std::queue<int> mq;
    LeetCode0225() {

    }

    void push(int x) {
        //������
        mq.push(x);
        //��ǰ�����ȫ�����������
        for (int i = 0; i < mq.size() - 1; i++)
        {
            mq.push(mq.front());
            mq.pop();
        }
    }

    int pop() {
        int num = mq.front();
        mq.pop();
        return num;
    }

    int top() {
        return mq.front();
    }

    bool empty() {
        return mq.empty();
    }

    void test()
    {
        LeetCode0225 myStack;
        myStack.push(1);
        myStack.push(2);
        std::cout<<myStack.top(); // ���� 2
        std::cout<<myStack.pop(); // ���� 2
        std::cout << myStack.top(); // ���� 1
        std::cout<<myStack.empty(); // ���� False
    }
};