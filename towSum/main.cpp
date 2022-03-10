//
//  main.cpp
//  towSum
//
//  Created by Xpeng on 2022/3/8.
//

#include <iostream>
#include "PintUtil.hpp"
#include "TwoSum.hpp"
#include "AddTwoNumbers.hpp"
#include "LengthOfLongestSubstringSolution.hpp"
#include "FindMedianSortedArraysSolution.hpp"

using namespace std;

void twoSum() {
    cout << "******************两数之和******************" << endl;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    
    vector<int> res = TwoSumSolution().twoSum(nums, target);
    
    printArray(res);
    cout << endl;
    cout << "******************两数之和******************" << endl;
}

void addTwoNumbers() {
    cout << "******************两数相加******************" << endl;
    int num1 = 45;
    int num2 = 98;
    ListNode *l1 = nullptr, *l1Tail = nullptr;
    ListNode *l2 = nullptr, *l2Tail = nullptr;
    while (num1 > 0) {
        if (l1 == nullptr) {
            l1 = l1Tail = new ListNode(num1 % 10);
        } else {
            l1Tail->next = new ListNode(num1 % 10);
            l1Tail = l1Tail->next;
        }
        num1 /= 10;
    }
    printListNode(l1);
    while (num2 > 0) {
        if (l2 == nullptr) {
            l2 = l2Tail = new ListNode(num2 % 10);
        } else {
            l2Tail->next = new ListNode(num2 % 10);
            l2Tail = l2Tail->next;
        }
        num2 /= 10;
    }
    printListNode(l2);
    ListNode *res = AddTwoNumbersSolution().addTwoNumbers(l1, l2);
    printListNode(res);
    cout << "******************两数相加******************" << endl;
}

void lengthOfLongestSubstring() {
    cout << "******************无重复字符的最长子串******************" << endl;
    string s = "abcabcbb";
    cout << "字符串: " << s << endl;
    int len = LengthOfLongestSubstringSolution().lengthOfLongestSubstring(s);
    cout << "result: " << len << endl;
    cout << "******************无重复字符的最长子串******************" << endl;
}

void findMedianSortedArrays() {
    cout << "******************寻找两个正序数组的中位数******************" << endl;
    vector<int> num1 = {1, 3, 5, 7};
    vector<int> num2 = {2, 4, 6};
    
    printArray(num1);
    printArray(num2);
    
    double result = FindMedianSortedArraysSolution().findMedianSortedArrays(num1, num2);
    cout << "result: " << result << endl;
    cout << "******************寻找两个正序数组的中位数******************" << endl;
}

int main(int argc, const char * argv[]) {
    
//    twoSum();
    
//    addTwoNumbers();
    
//    lengthOfLongestSubstring();
    
//    findMedianSortedArrays();
    
    return 0;
}
