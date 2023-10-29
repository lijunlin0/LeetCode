#pragma once

/*
名称：用栈实现队列

描述：请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
      实现 MyQueue 类：
      void push(int x) 将元素 x 推到队列的末尾
      int pop() 从队列的开头移除并返回元素
      int peek() 返回队列开头的元素
      boolean empty() 如果队列为空，返回 true ；否则，返回 false

解题思路：创建两个栈：输入栈 和 输出栈，在进行pop和peek操作时将 输入栈 的内容放在 输出栈 中。
*/

#include<stack>
#include<iostream>

class LeetCode0232 {
public:
    std::stack<int> inStack;//输入栈
    std::stack<int> outStack;//输出栈
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
