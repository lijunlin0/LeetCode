#pragma once
/*
���ƣ������ǰ׺

������
��дһ�������������ַ��������е������ǰ׺��
��������ڹ���ǰ׺�����ؿ��ַ��� ""��

����˼·��������ѭ��ʵ�֣���һ��ѭ�������ַ����ڶ���ѭ������ÿ���ַ�����������ĳһ�ַ��������򷵻ص���ǰ�±�ǰһ�����ַ�����������ĳһ�ַ��͹�ͬǰ׺��ͬ�򷵻ص���ǰ�±�ǰһ�����ַ�����
substr(i,j)�����ش�i�±꿪ʼ��j���ַ���
*/
#include<vector>
#include<iostream>
using namespace std;

class LeetCode0014
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int i = 0;
        while (true)
        {
            for (int j = 0; j < strs.size(); j++)
            {
                //����ַ������֣�����
                if (i >= strs[j].size())
                {
                    return strs[j].substr(0, i);
                }
                //��һ������ͬ���ַ���������
                if (strs[j][i] != strs[0][i])
                {
                    return strs[j].substr(0, i);
                }
            }
            i++;
        }
        //ȫ���ַ�����ͬ�����ص�һ��
        return strs[0];
    }
    void test()
    {
        vector<string> strs;
        strs.push_back("flower");
        strs.push_back("flower");
        strs.push_back("flower");
        cout<<longestCommonPrefix(strs);
    }
};