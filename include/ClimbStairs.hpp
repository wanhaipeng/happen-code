/** @file    ClimbStairs.cpp
 *  @brief   LeetCode problems 70: ClimbStairs implementation
 *  @author  ppeng
 *  @date    2019-06-16
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "extend.hpp"

class Solution {
 public:
  int climbStairs(int n) {
    // preprocess
    if (n < 2) {
      return n;
    }
    std::vector<int> dp(n, 0);
    dp[0] = 1; dp[1] = 2;
    for (int i = 2; i < n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
  }
};
