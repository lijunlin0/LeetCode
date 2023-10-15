#pragma once
/*
名称：快乐数

描述：
编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

示例：
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

解题思路：快慢指针：将每次计算的值放入一个隐式链表中，慢指针每次走一步，快指针每次走两步，如果链表无环则是快乐数，反之则不是。
*/

#include<iostream>

class LeetCode0202 {
public:
    //计算下一个值
    int get_next(int n)
    {
        int num = 0;
        while (n > 0)
        {
            num += (n % 10) * (n % 10);
            n /= 10;
        }
        return num;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = get_next(n);
        while (fast != 1 && fast != slow)
        {
            //走一步
            slow = get_next(slow);
            //走两步
            fast = get_next(get_next(fast));
        }
        return fast == 1;
    }

    void test()
    {
        std::cout << isHappy(19);
    }
};