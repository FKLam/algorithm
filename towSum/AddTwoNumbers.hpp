//
//  AddTwoNumbers.hpp
//  towSum
//
//  Created by Xpeng on 2022/3/9.
//

#ifndef AddTwoNumbers_hpp
#define AddTwoNumbers_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class AddTwoNumbersSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    void printListNode(ListNode *listNode);
};

#endif /* AddTwoNumbers_hpp */
