#pragma once

/*
名称：数字的补数

描述：对整数的二进制表示取反（0 变 1 ，1 变 0）后，再转换为十进制表示，可以得到这个整数的补数。
     例如，整数 5 的二进制表示是 "101" ，取反后得到 "010" ，再转回十进制表示得到补数 2 。
     给你一个整数 num ，输出它的补数。

解题思路：构造一个数mask，只要 mask<num 就将mask每次左移后再把最后一位变为1，以此找到num最高位的1的位置，再将num和mask进行异或，得到补数。
*/

class LeetCode0476 {
public:
    int findComplement(int num) {
        int mask = 1;
        //找到num最高位的1的位置
        while (mask < num)
        {
            mask = (mask << 1) | 1;
        }
        //异或
        num ^= mask;
        return num;
    }

    void test()
    {
        std::cout << findComplement(5);
    }
};