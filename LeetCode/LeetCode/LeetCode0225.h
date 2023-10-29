#pragma once

/*
名称：用队列实现栈

描述：请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

     实现 MyStack 类：
     void push(int x) 将元素 x 压入栈顶。
     int pop() 移除并返回栈顶元素。
     int top() 返回栈顶元素。
     boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

解题思路：主要实现push()，将要入栈的数推入队列，然后将其前面的数全部再次推入队列，并把前面的数全部推出队列，这样就进行了顺序调换可以进行pop()操作。
*/

#include<iostream>
#include<queue>

class LeetCode0225 {
public:
    std::queue<int> mq;
    LeetCode0225() {

    }

    void push(int x) {
        //推入数
        mq.push(x);
        //将前面的数全面调换到后面
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
        std::cout<<myStack.top(); // 返回 2
        std::cout<<myStack.pop(); // 返回 2
        std::cout << myStack.top(); // 返回 1
        std::cout<<myStack.empty(); // 返回 False
    }
};