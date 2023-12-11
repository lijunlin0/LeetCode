#pragma once

/*
���ƣ��绰�������ĸ���

����������һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�
     �������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��

����˼·:���ݷ��������ֶ�Ӧ����ĸ�����ϣ���У��ݹ麯����ѭ��������ǰindex��Ӧ��ÿһ����ĸ���������ʱ����У���index==digits.size()ʱ����һ�����
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
        //��index����digits�Ĵ�Сʱ(��ĸ��������)
        if (index == digits.size())
        {
            ans.push_back(current);
            return;
        }
        //����index���ֶ�Ӧ��ÿ����ĸ
        for (int i = 0; i < M[digits[index]].size(); i++)
        {
            //��ʱ����һ����ĸ
            current.push_back(M[digits[index]][i]);
            DFS(index + 1, digits);
            //��ԭ״̬
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