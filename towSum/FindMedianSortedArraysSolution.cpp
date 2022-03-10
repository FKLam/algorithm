//
//  FindMedianSortedArraysSolution.cpp
//  towSum
//
//  Created by Xpeng on 2022/3/10.
//

#include "FindMedianSortedArraysSolution.hpp"
#include <algorithm>

/*
 4. 寻找两个正序数组的中位数
 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

 算法的时间复杂度应该为 O(log (m+n)) 。
 */
double FindMedianSortedArraysSolution::getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    
    int index1 = 0, index2 = 0;
    while (true) {
        if (index1 == size1) {
            return nums2[index2 + k - 1];
        }
        if (index2 == size2) {
            return nums1[index1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[index1], nums2[index2]);
        }
        int indexNew1 = min(index1 + k / 2 - 1, size1 - 1);
        int indexNew2 = min(index1 + k / 2 - 1, size2 - 1);
        int val1 = nums1[indexNew1];
        int val2 = nums2[indexNew2];
        if (val1 <= val2) {
            k -= indexNew1 - index1 + 1;
            index1 = indexNew1 + 1;
        } else {
            k -= indexNew2 - index2 + 1;
            index2 = indexNew2 + 1;
        }
    }
}

double FindMedianSortedArraysSolution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    int size = size1 + size2;
    double result = 0.0;
    if ( size % 2 == 1 ) {
        // 奇数
        result = getKthElement(nums1, nums2, (size + 1) / 2);
    } else {
        // 偶数
        result = (getKthElement(nums1, nums2, size / 2 + 1) + getKthElement(nums1, nums2, size / 2)) / 2.0;
    }
    return result;
}

/// 暴力解法
double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2) {
    long size1 = nums1.size();
    long size2 = nums2.size();
    long size = size1 + size2;
    long k = size / 2;
    bool isMore = size % 2 == 0;    // 偶数
    
    int i = 0, j = 0;
    double result = 0.0;
    vector<int> array;
    while ((i < size1 || j < size2 )&& (i + j) <= k) {
        if (i + j > k) {
            break;
        }
        if (nums1[i] <= nums2[j] && i < size1) {
            array.push_back(nums1[i]);
            i++;
        } else if (j < size2) {
            array.push_back(nums2[j]);
            j++;
        }
        
        if (i >= size1 && j < size2) {
            array.push_back(nums2[j]);
            j++;
        } else if (i < size1 && j >= size2) {
            array.push_back(nums1[i]);
            i++;
        }
    }
    if (isMore) {
        result = (array[k - 1] + array[k]) * 1.0 / 2.0;
    } else {
        result = array[k];
    }
    return result;
}

