#pragma once

/*
���ƣ�Fizz Buzz

����������һ������ n ���ҳ��� 1 �� n ���������� Fizz Buzz ��ʾ�������ַ������� answer���±�� 1 ��ʼ�����ؽ�������У�
answer[i] == "FizzBuzz" ��� i ͬʱ�� 3 �� 5 �ı�����
answer[i] == "Fizz" ��� i �� 3 �ı�����
answer[i] == "Buzz" ��� i �� 5 �ı�����
answer[i] == i �����ַ�����ʽ�������������ȫ�����㡣

����˼·��������1��n�������ж��������ַ������뵽���С�
*/

#include<iostream>
#include<vector>
#include <string>

class LeetCode0412 {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> res;
        for (int i = 1; i <= n; i++)
        {
            //���ı���
            bool Fizz = i % 3 == 0;
            //��ı���
            bool Buzz = i % 5 == 0;
            if (Fizz && Buzz)
            {
                res.push_back("FizzBuzz");
            }
            else if (Fizz)
            {
                res.push_back("Fizz");
            }
            else if (Buzz)
            {
                res.push_back("Buzz");
            }
            else
            {
                res.push_back(std::to_string(i));
            }
        }
        return res;
    }

    void test()
    {
        std::vector<std::string> res = fizzBuzz(100);
        for (int i = 0; i < res.size(); i++)
        {
            if (i!=0&&i % 10 == 0)
            {
                std::cout << std::endl;
            }
            std::cout << res[i] << ',';
        }
    }
};