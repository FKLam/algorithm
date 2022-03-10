//
//  PintUtil.cpp
//  towSum
//
//  Created by Xpeng on 2022/3/10.
//

#include <iostream>
#include "PintUtil.hpp"

/// 打印数组元素
void printArray(const vector<int>&array) {
    cout << "[ ";
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
}

/// 打印链表元素
void printListNode(ListNode *listNode) {
    if (listNode == nullptr) {
        cout << "listNode is empty" << endl;
        return;
    }
    cout << "listNode:";
    while (listNode != nullptr) {
        cout << listNode->val;
        listNode = listNode->next;
        if (listNode != nullptr) {
            cout << "->";
        }
    }
    cout << endl;
}
