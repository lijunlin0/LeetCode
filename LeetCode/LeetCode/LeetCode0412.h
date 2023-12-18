#pragma once

/*
名称：Fizz Buzz

描述：给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：
answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
answer[i] == "Fizz" 如果 i 是 3 的倍数。
answer[i] == "Buzz" 如果 i 是 5 的倍数。
answer[i] == i （以字符串形式）如果上述条件全不满足。

解题思路：遍历从1到n，依次判断条件将字符串加入到答案中。
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
            //三的倍数
            bool Fizz = i % 3 == 0;
            //五的倍数
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