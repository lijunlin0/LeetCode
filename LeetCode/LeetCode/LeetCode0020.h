#pragma once
/*
名称：有效的括号

描述：
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号
。
解题思路：使用栈(stack)，判断当前字符和栈顶字符是否匹配，最后栈为空则匹配。
*/
#include<iostream>
#include<stack>
using namespace std;

class LeetCode0020
{
public:
    bool isValid(string s)
    {
        stack<int> a;
        for (int i = 0; i < s.length(); i++)
        {
            //如果栈为空则将指定字符入栈
            if (a.empty())
            {
                a.push(s[i]);
            }
            else
            {
                //当前字符
                char c1 = s[i];
                //栈顶字符
                char c2 = a.top();
                //如果匹配成功则出栈，否则入栈
                if (c2 == '(' && c1 == ')' || c2 == '{' && c1 == '}' || c2 == '[' && c1 == ']')
                {
                    a.pop();
                }
                else
                {
                    a.push(s[i]);
                }
            }
        }
        //栈为空则匹配成功
        return a.empty();
    }
    void test()
    {
        string s = "([{}])";
        cout<<isValid(s);
    }
};
