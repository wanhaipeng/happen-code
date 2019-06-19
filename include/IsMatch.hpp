/** @file    IsMatch.cpp
 *  @brief   LeetCode problems 10:  IsMatch implementation
 *  @author  ppeng
 *  @date    2019-06-18
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "extend.hpp"
/**
 * s:aa p:a false
 * s:aa p:a* true
 * s:ab p:.* true
 * s:aab p:c*a*b true
 * s:mississippi p:mis*is*p*. false
 */
class Solution {
 public:
  bool isMatch(std::string s, std::string p) {
    int s_len = s.length(), p_len = p.length();
    // len + 1 for '' match ''
    std::vector<std::vector<bool>> dp(s_len + 1, std::vector<bool>(p_len + 1, false));
    for (int i = s_len; i >= 0; i--) {
      for (int j = p_len; j >= 0; j--) {
        spdlog::error("({},{})", i, j);
        if (i == s_len && j == p_len) {
          dp[s_len][p_len] = true;
        } else {
          bool now_match = (i < s_len && j < p_len && (s[i] == p[j] || p[j] == '.'));
          if (j < p_len - 1 && p[j + 1] == '*') {
            dp[i][j] = dp[i][j + 2] || now_match && dp[i + 1][j];
          } else {
            dp[i][j] = now_match && dp[i + 1][j + 1];
          }
        }
      }
    }
    return dp[0][0];
  }
};