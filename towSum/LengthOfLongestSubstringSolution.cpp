//
//  LengthOfLongestSubstringSolution.cpp
//  towSum
//
//  Created by Xpeng on 2022/3/9.
//

#include "LengthOfLongestSubstringSolution.hpp"
#include <map>
#include <algorithm>
#include <iostream>

/*
 3. 无重复字符的最长子串
 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 */

void printString(string s, int start, int end) {
    cout << "有重复字符前的长度 len:" << end - start << " " << "start:" << start << " end:" << end << " 字符串为： ";
    long size = s.size();
    for (int index = start; index < end && index < size; index++) {
        cout << s[index];
    }
    cout << endl;
}

int LengthOfLongestSubstringSolution::lengthOfLongestSubstring(string s) {
    int len = 0;
    if (s.size() == 0) {
        return len;
    }
    if (s.size() == 1) {
        return 1;
    }
    map<char, int> hashtable;
    int start = 0, end = 0;
    long size = s.size();
    for (; end < size; end++) {
        auto res = hashtable.find(s[end]);
        if (res != hashtable.end()) {
            printString(s, start, end);
            start = max(res->second + 1, start);
        }
        len = max(len, end - start + 1);
        hashtable[s[end]] = end;
    }
    return len;
}


