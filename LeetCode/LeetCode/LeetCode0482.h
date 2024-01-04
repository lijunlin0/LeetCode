#pragma once

/*
���ƣ���Կ��ʽ��

����������һ�������Կ�ַ��� s��������ĸ�������ַ������ۺ���ɡ��ַ����� n �����ۺŷֳ� n + 1 �顣��Ҳ��õ�һ������ k ��
     ������Ҫ���¸�ʽ���ַ��� s��ʹÿһ����� k ���ַ������˵�һ�飬�����Ա� k �̣�����Ȼ�����������һ���ַ���
     ���⣬����֮�����������ۺţ�����Ӧ�ý�����Сд��ĸת��Ϊ��д��ĸ���������¸�ʽ���������Կ ��

����˼·���Ӻ���ǰ��������count��¼����res����ĸ��������count%k==0ʱ������Ҫ������ۺ��ˡ�
         ��������жϣ�������ַ�����Ϊ�ղ������һ�������ۺ�ʱ��ȥ�����ٷ�ת����ַ�����
*/

#include<iostream>

class LeetCode0482 {
public:
    std::string licenseKeyFormatting(std::string s, int k) {
        //������ĸ��
        int count = 0;
        std::string res;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != '-')
            {
                //ת��д��ĸ
                res += toupper(s[i]);
                count++;
                //������ۺ�
                if (count % k == 0)
                {
                    res += '-';
                }
            }
        }
        //�ж����һ���Ƿ�Ϊ���ۺ�
        if (res.size() > 0 && res.back() == '-')
        {
            res.pop_back();
        }
        //��ת�ַ���
        std::reverse(res.begin(), res.end());
        return res;
    }

    void test()
    {
        std::cout << licenseKeyFormatting("2-5g-3-J",2);
    }
};