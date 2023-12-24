#pragma once

/*
名称：括号生成

描述：数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

解题思路：回溯：
         left==0&&right==0：括号用完了，返回结果
         left==right:只能用左括号
         left<right:可以用左括号也能用右括号
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
        //剩余左右括号数相等，下一个只能用左括号
        if (left == right)
        {
            getParenthesis(str + "(", left - 1, right);
        }
        //剩余左括号小于右括号，下一个可以用左括号也可以用右括号
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