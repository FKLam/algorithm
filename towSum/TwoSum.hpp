//
//  TwoSum.hpp
//  towSum
//
//  Created by Xpeng on 2022/3/8.
//

#ifndef TwoSum_hpp
#define TwoSum_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class TwoSumSolution {
public:
    // 哈希表
    vector<int> twoSum(vector<int>& nums, int target);
    // 暴力解法
    vector<int> twoSum1(vector<int>& nums, int target);
};


#endif /* TwoSum_hpp */
