//
//  AddTwoNumbers.cpp
//  towSum
//
//  Created by Xpeng on 2022/3/9.
//

#include "AddTwoNumbers.hpp"
#include <iostream>

using namespace std;
/*
 2. 两数相加
 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

 请你将两个数相加，并以相同形式返回一个表示和的链表。

 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 */
ListNode *AddTwoNumbersSolution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *header = nullptr, *tail = nullptr;
    int carray = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        int sum = v1 + v2 + carray;
        if (header == nullptr) {
            header = tail = new ListNode(sum % 10);
        } else {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carray = sum / 10;
        if (l1 != nullptr) {
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            l2 = l2->next;
        }
    }
    if (carray > 0) {
        tail->next = new ListNode(carray);
    }
    return header;
}

void AddTwoNumbersSolution::printListNode(ListNode *listNode) {
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
