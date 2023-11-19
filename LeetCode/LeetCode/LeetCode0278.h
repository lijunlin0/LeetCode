#pragma once

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/*
名称：第一个错误的版本

描述：假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
     你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。
     实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例：
输入：n = 5, bad = 4
输出：4
解释：
调用 isBadVersion(3) -> false
调用 isBadVersion(5) -> true
调用 isBadVersion(4) -> true
所以，4 是第一个错误的版本。

解题思路：二分查找法
*/

#include<iostream>

class LeetCode0278 {
public:
    bool isBadVersion(int n)
    {
        return n == 4;
    }
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    void test()
    {
        std::cout<< firstBadVersion(5);
    }
};