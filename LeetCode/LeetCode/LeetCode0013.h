#pragma once

/*
名称：罗马数字转整数

描述：罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，
所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。

解题思路：遍历字符串，根据字符对应的数字，判断 下一个字符对应的数字 是否比 当前字符对应的数字 大，根据他们的大小关系进行加减操作。
*/

#include<iostream>
class LeetCode0013 {
public:
    int romanToInt(std::string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            //判断是否是特殊字符（相减的字符）
            int value = get_value(s[i]);
            if (i != s.size() - 1 && value < get_value(s[i + 1]))
            {
                res -= value;
            }
            else
            {
                res += value;
            }
        }
        return res;
    }

    int get_value(char c)
    {
        switch (c)
        {
        case'I':return 1; break;
        case'V':return 5; break;
        case'X':return 10; break;
        case'L':return 50; break;
        case'C':return 100; break;
        case'D':return 500; break;
        case'M':return 1000; break;
        default:
            return 0;
        }
    }
    
    void test()
    {
        std::cout<<romanToInt("MIX");
    }
};