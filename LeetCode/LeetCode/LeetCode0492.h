#pragma once

/*
���ƣ��������

��������Ϊһλweb�����ߣ� ��������ȥ�滮һ��ҳ��ĳߴ��Ǻ���Ҫ�ġ� ���ԣ��ָ���һ������ľ���ҳ�������
     ������������һ������Ϊ L �Ϳ��Ϊ W ����������Ҫ��ľ��ε�ҳ�档
     Ҫ������Ƶľ���ҳ�������ڸ�����Ŀ�������
     ��� W ��Ӧ���ڳ��� L ������֮��Ҫ�� L >= W ��
     ���� L �Ϳ�� W ֮��Ĳ��Ӧ��������С��
     ����һ�� ���� [L, W]������ L �� W ���㰴��˳����Ƶ���ҳ�ĳ��ȺͿ�ȡ�

����˼·��Ҫ������С��L��W����ô���ֵ�϶���area��ƽ������ʼ�ݼ��ҵ���һ��������������
*/

#include<iostream>
#include<vector>

class LeetCode0492 {
public:
    std::vector<int> constructRectangle(int area) {
        //��ƽ����
        int i = sqrt(area);
        for (; i >= 0; i--)
        {
            if (area % i == 0)
            {
                return std::vector<int>() = { area / i,i };
            }
        }
        return std::vector<int>() = { area / i,i };
    }

    void test()
    {
        std::cout<<constructRectangle(122122)[0]<<',' << constructRectangle(122122)[1];
    }
};

