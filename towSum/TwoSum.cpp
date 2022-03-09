//
//  TwoSum.cpp
//  towSum
//
//  Created by Xpeng on 2022/3/8.
//

#include "TwoSum.hpp"
#include <map>
#include <vector>

/*
 1. 两数之和
 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

 你可以按任意顺序返回答案。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/two-sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
vector<int> TwoSumSolution::twoSum(vector<int>& nums, int target) {
    map<int, int> hashtable;
    for (int index = 0; index < nums.size(); index++) {
        cout << "index:" << index << " " << nums[index] << endl;
        auto res = hashtable.find(target - nums[index]);
        if (res != hashtable.end()) {
            return {res->second, index};
        }
        hashtable[nums[index]] = index;
    }
    return {};
}

vector<int> TwoSumSolution::twoSum1(vector<int>& nums, int target) {
    long size = nums.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}
