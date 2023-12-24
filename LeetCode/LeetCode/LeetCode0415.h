#pragma once

/*
���ƣ��ַ������

���������������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺͲ�ͬ�����ַ�����ʽ���ء�
     �㲻��ʹ���κ΃Ƚ������ڴ���������Ŀ⣨���� BigInteger���� Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��

����˼·���Ӻ���ǰ���������ַ�����������ӣ�����¼��λֵ�����ַ���������ʱ����Ӧλ�ò�0������λֵ��Ϊ0���轫��λֵ���ϡ�     
*/

#include<iostream>
#include<string>

class LeetCode0415 {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int count = 0;
        std::string res = "";
        for (int i = num1.size() - 1, j = num2.size() - 1; j >= 0 || i >= 0; i--, j--)
        {
            //����������0
            int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
            int digit2 = (j >= 0) ? (num2[j] - '0') : 0;
            
            //����֮�ͼӽ�λֵ
            int sum = digit1 + digit2 + count;
            count = 0;
            //��Ҫ��λ
            if (sum >= 10)
            {
                count = 1;
                sum -= 10;
            }
            res += std::to_string(sum);
        }
        //����λֵ��Ϊ0����Ͻ�λֵ
        if (count != 0)
        {
            res += std::to_string(count);
        }
        //��ת�ַ���
        reverse(res.begin(), res.end());
        return res;
    }

    void test()
    {
        std::cout << addStrings("456", "77");
    }
};