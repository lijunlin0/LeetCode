#pragma once

#include<iostream>
#include<string>

class LeetCode0415 {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int count = 0;
        std::string res = "";
        for (int i = num1.size() - 1, j = num2.size() - 1; j >= 0 || i >= 0; i--, j--)
        {
            int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
            int digit2 = (j >= 0) ? (num2[j] - '0') : 0;
            int sum = digit1 + digit2 + count;
            count = 0;
            if (sum >= 10)
            {
                count = 1;
                sum -= 10;
            }
            res += std::to_string(sum);
        }
        if (count != 0)
        {
            res += std::to_string(count);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void test()
    {
        std::cout << addStrings("456", "77");
    }
};