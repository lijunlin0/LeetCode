#pragma once

/*
���ƣ�N ���α任

��������һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�
     ���������ַ���Ϊ "PAYPALISHIRING" ����Ϊ 3 ʱ���������£�
     P   A   H   N
     A P L S I I G
     Y   I   R
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"PAHNAPLSIIGYIR"��

����˼·������һ��������С���ַ������飬��s��ÿ���ַ�Ϊrows�е��Ӵ�����˳���С->��->С�仯���и�ֵ���ڵ�һ���ַ��������һ���ַ���ʱ���з���仯��ѭ��������
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
		//���ڸı䷽��
		int flag = -1;
		for (int j = 0; j < s.size(); j++)
		{
			rows[i].push_back(s[j]);
			//�����������һ�������һ���Ӵ���ı䷽��
			if (i == 0 || i == numRows - 1)
			{
				flag = -flag;
			}
			i += flag;
		}
		//�����ַ���
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