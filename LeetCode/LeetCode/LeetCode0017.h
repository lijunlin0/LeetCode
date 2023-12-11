#pragma once

/*
名称：电话号码的字母组合

描述：给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
     给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

解题思路:回溯法：将数字对应的字母存入哈希表中，递归函数中循环遍历当前index对应的每一个字母将其加入临时结果中，待index==digits.size()时返回一个结果
*/

#include<iostream>
#include<vector>
#include<unordered_map>
class LeetCode0017 {
public:
    std::unordered_map<char, std::string > M = {
       {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
       {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    std::vector<std::string> ans;
    std::string current;

    void DFS(int index, std::string digits)
    {
        //当index等于digits的大小时(字母数量够了)
        if (index == digits.size())
        {
            ans.push_back(current);
            return;
        }
        //遍历index数字对应的每个字母
        for (int i = 0; i < M[digits[index]].size(); i++)
        {
            //临时加入一个字母
            current.push_back(M[digits[index]][i]);
            DFS(index + 1, digits);
            //还原状态
            current.pop_back();
        }
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.size() == 0)
        {
            return ans;
        }
        DFS(0, digits);
        return ans;
    }



    void test()
    {
        std::vector<std::string> res = letterCombinations("2345");
        for (int i = 0; i < res.size(); i++)
        {
            std::cout << res[i] << ' ';
        }
    }
};