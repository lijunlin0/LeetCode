#pragma once

/*
名称：密钥格式化

描述：给定一个许可密钥字符串 s，仅由字母、数字字符和破折号组成。字符串由 n 个破折号分成 n + 1 组。你也会得到一个整数 k 。
     我们想要重新格式化字符串 s，使每一组包含 k 个字符，除了第一组，它可以比 k 短，但仍然必须包含至少一个字符。
     此外，两组之间必须插入破折号，并且应该将所有小写字母转换为大写字母。返回重新格式化的许可密钥 。

解题思路：从后往前遍历，用count记录存入res的字母个数，当count%k==0时代表需要添加破折号了。
         最后特殊判断，当结果字符串不为空并且最后一个是破折号时则去掉，再反转结果字符串。
*/

#include<iostream>

class LeetCode0482 {
public:
    std::string licenseKeyFormatting(std::string s, int k) {
        //存入字母数
        int count = 0;
        std::string res;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != '-')
            {
                //转大写字母
                res += toupper(s[i]);
                count++;
                //添加破折号
                if (count % k == 0)
                {
                    res += '-';
                }
            }
        }
        //判断最后一个是否为破折号
        if (res.size() > 0 && res.back() == '-')
        {
            res.pop_back();
        }
        //反转字符串
        std::reverse(res.begin(), res.end());
        return res;
    }

    void test()
    {
        std::cout << licenseKeyFormatting("2-5g-3-J",2);
    }
};