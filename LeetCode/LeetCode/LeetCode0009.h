#pragma once
/*
名称: 回文数

描述:
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

解题思路:
反转一半的的字符:将后半部分和前半部分整数相比 例如：1221
将1221%10得到最后一位数1，再将原来的数1221/10得到去除末尾数的数122，再将此数%10得到倒数第二个数2，将上一个数1*10+2得到反转后的数，再将122/10得到12。
另外，当整数x为奇数时，例：12321 因为中位数总是和自己相等，不影响判断，所以只需要将反转数/10把中位数去除。
结束条件：反转数小于或者等于原来的数时。
*/
#include<iostream>
#include<vector>
using namespace std;

class LeetCode0009 {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0))
        {
            return false;
        }
        int reverted_number = 0;
        while (x > reverted_number)
        {
            reverted_number = reverted_number * 10 + x % 10;
            x /= 10;
        }
        return x == reverted_number || x == reverted_number / 10;
    }
    void test()
    {
        cout<<isPalindrome(12321);
    }
};

