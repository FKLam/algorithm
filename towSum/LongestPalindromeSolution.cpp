//
//  LongestPalindromeSolution.cpp
//  towSum
//
//  Created by Xpeng on 2022/3/11.
//

#include "LongestPalindromeSolution.hpp"
#include <vector>
#include <algorithm>

/*
 5. 最长回文子串
 给你一个字符串 s，找到 s 中最长的回文子串。
 */

string LongestPalindromeSolution::longestPalindrome(string s) {
    /*
     边界：
     1、一个元素     P[i,i] = true
     2、两个元素     P[i,j] = Si == Sj
     3、多个元素     P[i,j] = P[i+1,j-1]^Si==Sj
     
     状态转移：
     当前状态依赖于上一状态
     */
    long size = s.size();
    if (size < 2) {                                                         // 长度为1的字符串本身就是最长回文
        return s;
    }
    int start = 0, end = 0;
    for (int index = 0; index < size; index++) {                            // 遍历所有边界条件
        auto [left1, right1] = expandAroundCenter(s, index, index);         // 一个元素情况
        auto [left2, right2] = expandAroundCenter(s, index, index + 1);     // 两个元素情况
        if (right1 - left1 > end - start) {
            start = left1;
            end = right1;
        }
        
        if (right2 - left2 > end - start) {
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1);
}

pair<int, int> LongestPalindromeSolution::expandAroundCenter(const string&s, int left, int right) {
    /*
     如果头尾元素相同，向两侧扩散，--left，++right
     */
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return {left + 1, right - 1};
}

/// 暴力解法
string longestPalindrome1(string s) {
    long size = s.size();
    if (size < 2) {                                     // 长度为1的字符串本身就是最长回文
        return s;
    }
    long maxLen = 1;                                    // 默认最长回文长度为1
    int start = 0;                                      // 默认最长回文起始坐标为0
    vector<vector<bool>> dp(size, vector<bool>(size));  // 初始化二维数组 size x size，dp[i][j],代表s[i,...,j]的字符串是否为回文
    for (int index = 0; index < size; index++) {
        dp[index][index] = true;                        // 单个字符串都是回文
    }
    for (int l = 2; l <= size; l++) {                   // 从长度为2开始遍历所有长度的情况
        for (int i = 0; i < size; i++) {                // 起始位置从0开始
            int j = l + i - 1;                          // 结束位置为j，长度l = j - i + 1
            if (j >= size) {                            // 结束位置边界
                break;;
            }
            if (s[i] != s[j]) {                         // 如果头部、尾部元素不等，不是回文
                dp[i][j] = false;
            } else {
                if (j - i < 3) {                        // 少于三个元素，且头尾元素相等，是回文
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];        // 多余三个元素，头尾元素相等，看更小范围是否为回文
                }
            }
            if (dp[i][j] && j - i + 1 > maxLen) {       // 判断是否为更长的回文，记录起始位置
                maxLen = j - i + 1;
                start = i;
            }
        }
    }
    return s.substr(start, maxLen);
}

