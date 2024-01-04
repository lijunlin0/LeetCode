#pragma once

/*
���ƣ����ֵĲ���

�������������Ķ����Ʊ�ʾȡ����0 �� 1 ��1 �� 0������ת��Ϊʮ���Ʊ�ʾ�����Եõ���������Ĳ�����
     ���磬���� 5 �Ķ����Ʊ�ʾ�� "101" ��ȡ����õ� "010" ����ת��ʮ���Ʊ�ʾ�õ����� 2 ��
     ����һ������ num ��������Ĳ�����

����˼·������һ����mask��ֻҪ mask<num �ͽ�maskÿ�����ƺ��ٰ����һλ��Ϊ1���Դ��ҵ�num���λ��1��λ�ã��ٽ�num��mask������򣬵õ�������
*/

class LeetCode0476 {
public:
    int findComplement(int num) {
        int mask = 1;
        //�ҵ�num���λ��1��λ��
        while (mask < num)
        {
            mask = (mask << 1) | 1;
        }
        //���
        num ^= mask;
        return num;
    }

    void test()
    {
        std::cout << findComplement(5);
    }
};