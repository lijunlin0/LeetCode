#pragma once
/*
���ƣ��ҳ��ַ����е�һ��ƥ������±�

������
���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle �ַ����ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ������� needle ���� haystack ��һ���֣��򷵻�  -1 ��

����˼·��
���������ַ�������ÿ��λ��ѭ��ƥ�䡣
*/
#include<iostream>
using namespace std;

class LeetCode0028
{
public:
	int strStr(string haystack, string needle) 
	{
		//���������ַ���
		for (int i = 0; i < haystack.length(); i++)
		{
			bool truth = false;
			//��iλ�ô���ȥ�����ж�
			for (int j = 0, k = i; j < needle.length(); j++, k++)
			{
				if (haystack[k] == needle[j])
				{
					truth = true;
				}
				//��;��һ���ַ���ƥ�����˳�ѭ��
				else
				{
					truth = false;
					break;
				}
			}
			//�ҵ��򷵻�
			if (truth == true)
			{
				return i;
			}
		}
		//δ�ҵ�
		return -1;
	}
	void test()
	{
		string s1 = "99leetcode";
		string s2 = "leetc";
		cout << strStr(s1,s2) << endl;
	}
};
