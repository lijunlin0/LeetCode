#pragma once

/*
���ƣ���ջʵ�ֶ���

�����������ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
      ʵ�� MyQueue �ࣺ
      void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
      int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
      int peek() ���ض��п�ͷ��Ԫ��
      boolean empty() �������Ϊ�գ����� true �����򣬷��� false

����˼·����������ջ������ջ �� ���ջ���ڽ���pop��peek����ʱ�� ����ջ �����ݷ��� ���ջ �С�
*/

#include<stack>
#include<iostream>

class LeetCode0232 {
public:
    std::stack<int> inStack;//����ջ
    std::stack<int> outStack;//���ջ
    LeetCode0232() {

    }
    void out()
    {
        while (!inStack.empty())
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty())
        {
            out();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    int peek() {
        if (outStack.empty())
        {
            out();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }

    void test()
    {
        LeetCode0232* queue = new LeetCode0232();
        queue->push(3);
        std::cout << queue->peek();
        int param_2 = queue->pop();
        std::cout << queue->empty();
    }
};
