//
//  main.cpp
//  towSum
//
//  Created by Xpeng on 2022/3/8.
//

#include <iostream>
#include "TwoSum.hpp"
#include "AddTwoNumbers.hpp"

using namespace std;

void twoSum() {
    cout << "******************两数之和******************" << endl;
    //    vector<int> nums = {2,7,11,15};
    //    int target = 9;
        
    //    vector<int> nums = {3,2,4};
    //    int target = 6;
        
    vector<int> nums = {3,3};
    int target = 6;
    
    vector<int> res = TwoSumSolution().twoSum(nums, target);
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
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
    AddTwoNumbersSolution().printListNode(l1);
    while (num2 > 0) {
        if (l2 == nullptr) {
            l2 = l2Tail = new ListNode(num2 % 10);
        } else {
            l2Tail->next = new ListNode(num2 % 10);
            l2Tail = l2Tail->next;
        }
        num2 /= 10;
    }
    AddTwoNumbersSolution().printListNode(l2);
    ListNode *res = AddTwoNumbersSolution().addTwoNumbers(l1, l2);
    AddTwoNumbersSolution().printListNode(res);
    cout << "******************两数相加******************" << endl;
}

int main(int argc, const char * argv[]) {
    
//    twoSum();
    
    addTwoNumbers();
    
    return 0;
}
