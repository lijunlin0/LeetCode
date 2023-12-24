#pragma once

/*
���ƣ��ַ�����

��������������һλ�ܰ��ļҳ�����Ҫ����ĺ�����һЩС���ɡ����ǣ�ÿ���������ֻ�ܸ�һ����ɡ���ÿ������ i������һ��θ��ֵ g[i]��
     �������ú���������θ�ڵı��ɵ���С�ߴ磻����ÿ����� j������һ���ߴ� s[j] ����� s[j] >= g[i]�����ǿ��Խ�������� j ��������� i ��
     ������ӻ�õ����㡣���Ŀ���Ǿ���������Խ�������ĺ��ӣ��������������ֵ��

����˼·������+˫ָ��+̰�ģ���������������ָ��ֱ�ָ��ͷ���������������飬�ڴ�ѭ�����������ʺϵı��ɣ��жϸ�λ���Ƿ�Ϊ���б��ɡ�
*/

#include<iostream>
#include<vector>
#include<queue>

class LeetCode0455 {
public:
    int findContentChildren(std::vector<int>&g, std::vector<int>& s) {
        //����
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;

        for (int i = 0, j = 0; i < g.size() && j < s.size(); i++, j++)
        {
            //�������ʺϵı���
            while (j < s.size() && s[j] < g[i])
            {
                j++;
            }
            //�Ƿ����
            if (j < s.size())
            {
                result++;
            }
        }
        return result;
    }

    void test()
    {
        std::cout << findContentChildren(std::vector<int>() = { 1,2,3 }, std::vector<int>() = { 1,1 });
    }
};