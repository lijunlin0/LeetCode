#pragma once

/*
���ƣ��ж�������

�����������ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С��ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ����
     �ַ������ı�ʣ���ַ����λ���γɵ����ַ����������磬"ace"��"abcde"��һ�������У���"aec"���ǣ���

����˼·��˫ָ��i,jָ���ַ���s,t���ײ���j������ǰѰ�ң������±�λ��Ԫ����ͬʱiǰ��һ�Ρ�ѭ������ʱ�ж�i�Ƿ����s�Ĵ�С��
*/

#include<iostream>

class LeetCode0392 {
public:
    //˫ָ��
    bool isSubsequence(std:: string s, std::string t) {
        int i = 0;
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i] == t[j])
            {
                i++;
            }
        }
        return i == s.size();
    }

    void test()
    {
        std::cout << (isSubsequence("abc", "ahgbsc")?"true" : "false");
    }
};