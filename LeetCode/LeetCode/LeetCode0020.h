#pragma once
/*
���ƣ���Ч������

������
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵�������
��
����˼·��ʹ��ջ(stack)���жϵ�ǰ�ַ���ջ���ַ��Ƿ�ƥ�䣬���ջΪ����ƥ�䡣
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
            //���ջΪ����ָ���ַ���ջ
            if (a.empty())
            {
                a.push(s[i]);
            }
            else
            {
                //��ǰ�ַ�
                char c1 = s[i];
                //ջ���ַ�
                char c2 = a.top();
                //���ƥ��ɹ����ջ��������ջ
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
        //ջΪ����ƥ��ɹ�
        return a.empty();
    }
    void test()
    {
        string s = "([{}])";
        cout<<isValid(s);
    }
};
