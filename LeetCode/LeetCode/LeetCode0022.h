#pragma once

/*
���ƣ���������

���������� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�

����˼·�����ݣ�
         left==0&&right==0�����������ˣ����ؽ��
         left==right:ֻ����������
         left<right:������������Ҳ����������
*/

#include<iostream>
#include<vector>

class LeetCode0022 {
public:
    std::vector<std::string> res;
    std::vector<std::string> generateParenthesis(int n) {
        getParenthesis("", n, n);
        return res;
    }
    void getParenthesis(std::string str, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(str);
            return;
        }
        //ʣ��������������ȣ���һ��ֻ����������
        if (left == right)
        {
            getParenthesis(str + "(", left - 1, right);
        }
        //ʣ��������С�������ţ���һ��������������Ҳ������������
        else if (left < right)
        {
            if (left > 0)
            {
                getParenthesis(str + "(", left - 1, right);
            }
            getParenthesis(str + ")", left, right - 1);
        }
    }

    void test()
    {
        std::vector<std::string> res = generateParenthesis(3);
        for (int i = 0; i < res.size(); i++)
        {
            std::cout << res[i] << ',';
        }
    }
};