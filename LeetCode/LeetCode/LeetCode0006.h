#pragma once

/*
名称：N 字形变换

描述：将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
     比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
     P   A   H   N
     A P L S I I G
     Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

解题思路：创建一个行数大小的字符串数组，将s中每个字符为rows中的子串按照顺序从小->大->小变化进行赋值，在第一个字符串和最后一个字符串时进行方向变化，循环往复。
*/

#include<iostream>
#include<vector>

class LeetCode0006
{
public:
	std::string convert(std::string s, int numRows) {
		if (numRows < 2)
		{
			return s;
		}
		std::vector<std::string> rows(numRows+1);
		int i = 0;
		//用于改变方向
		int flag = -1;
		for (int j = 0; j < s.size(); j++)
		{
			rows[i].push_back(s[j]);
			//如果遍历到第一个或最后一个子串则改变方向
			if (i == 0 || i == numRows - 1)
			{
				flag = -flag;
			}
			i += flag;
		}
		//连接字符串
		std::string result;
		for (int i = 0; i < rows.size(); i++)
		{
			result += rows[i];
		}
		return result;
	}

	void test()
	{
		std::string s= "LEETCOD";
		std::cout<<convert(s, 3);
	}
};