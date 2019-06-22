/** @file    MaxSubarray.hpp
 *  @brief   LeetCode problems 53: MaxSubarray implementation
 *  @author  ppeng
 *  @date    2019-06-06
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "extend.hpp"

typedef struct Inner_status {
  int value;
  int head;
}inner_status;

class Solution {
 public:
  Solution() = default;
  int maxSubArray(std::vector<int>& nums) {
    int array_size = nums.size();
    if (array_size == 1) return nums[0]; // special case
    std::vector<inner_status> status;
    int pos = 0, max_value = INT_MIN;
    for (int i = 0; i < array_size; i++) {
      inner_status temp;
      if (i == 0) {
        temp.value = nums[i];
        temp.head = i;
      } else {
        temp.value = std::max(status[i-1].value + nums[i], nums[i]);
        temp.head = (temp.value == nums[i]) ? i : status[i-1].head;
      }
      if (max_value < temp.value) {
        max_value = temp.value;
        pos = i;
      }
      status.push_back(temp);
    }
    return max_value;
  }
};