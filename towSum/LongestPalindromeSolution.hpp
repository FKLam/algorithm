//
//  LongestPalindromeSolution.hpp
//  towSum
//
//  Created by Xpeng on 2022/3/11.
//

#ifndef LongestPalindromeSolution_hpp
#define LongestPalindromeSolution_hpp

#include <stdio.h>
#include <string>

using namespace std;

class LongestPalindromeSolution {
public:
    string longestPalindrome(string s);
    pair<int, int> expandAroundCenter(const string&s, int left, int right);
};

#endif /* LongestPalindromeSolution_hpp */
