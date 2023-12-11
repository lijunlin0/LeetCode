#pragma once

/*
���ƣ��������ֱ�

�������������ֱ����� 4 �� LED ���� Сʱ��0-11�����ײ��� 6 �� LED ���� ���ӣ�0-59����ÿ�� LED ����һ�� 0 �� 1�����λ���Ҳࡣ
     ����һ������ turnedOn ����ʾ��ǰ���ŵ� LED �����������ض������ֱ���Ա�ʾ�����п���ʱ�䡣����� ������˳�� ���ش𰸡�
     Сʱ�������㿪ͷ��
     ���磬"01:00" ����Ч��ʱ�䣬��ȷ��д��Ӧ���� "1:00" ��
     ���ӱ�������λ����ɣ����ܻ����㿪ͷ��
     ���磬"10:2" ����Ч��ʱ�䣬��ȷ��д��Ӧ���� "10:02" ��

����˼·��ͨ��˫��ѭ������ÿСʱÿ���Ӳ����� Сʱ�ͷ������ڶ�������1�ĸ����ĺ� �Ƿ� ����n��
*/

#include<iostream>
#include<vector>
#include <string>
class LeetCode0401 {
public:
    //����һ�����ڶ������е�1����
    int count(int n)
    {
        int res = 0;
        while (n)
        {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> res;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                if (count(i) + count(j) == turnedOn)
                {
                    res.push_back(std::to_string(i) + ":" + (j < 10 ? "0" + std::to_string(j) : std::to_string(j)));
                }
            }
        }
        return res;
    }

    void test()
    {
        std::vector<std::string> res = readBinaryWatch(1);
        for (int i = 0; i < res.size(); i++)
        {
            std::cout << res[i] << ' ';
        }
    }
};