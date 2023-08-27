#pragma once
/*
名称：找出字符串中第一个匹配项的下标

描述：
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

解题思路：
遍历整个字符串，将每个位置循环匹配。
*/
#include<iostream>
using namespace std;

class LeetCode0028
{
public:
	int strStr(string haystack, string needle) 
	{
		//遍历整个字符串
		for (int i = 0; i < haystack.length(); i++)
		{
			bool truth = false;
			//将i位置传进去进行判断
			for (int j = 0, k = i; j < needle.length(); j++, k++)
			{
				if (haystack[k] == needle[j])
				{
					truth = true;
				}
				//中途有一个字符不匹配则退出循环
				else
				{
					truth = false;
					break;
				}
			}
			//找到则返回
			if (truth == true)
			{
				return i;
			}
		}
		//未找到
		return -1;
	}
	void test()
	{
		string s1 = "99leetcode";
		string s2 = "leetc";
		cout << strStr(s1,s2) << endl;
	}
};
