#pragma once

#include<iostream>

class LeetCode0434 {
public:
    int countSegments(std::string s) {
        int segmentCount = 0;

        for (int i = 0; i < s.size(); i++) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                segmentCount++;
            }
        }

        return segmentCount;
    }

    void test()
    {
        std::cout<<countSegments(", , , ,        a, eaefa");
    }
};