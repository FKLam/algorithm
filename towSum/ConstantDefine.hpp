//
//  ConstantDefine.hpp
//  towSum
//
//  Created by Xpeng on 2022/3/10.
//

#ifndef ConstantDefine_hpp
#define ConstantDefine_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif /* ConstantDefine_hpp */
