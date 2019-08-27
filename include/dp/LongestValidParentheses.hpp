/** @file    LongestValidParentheses.hpp
 *  @brief   LeetCode problems 32:  LongestValidParentheses implementation
 *  @author  ppeng
 *  @date    2019-06-17
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "extend.hpp"

class Solution {
 private:
  std::pair<int, int> checkparentheses(int pos, std::string substr) {
    std::pair<int, int> output;
    int checkpoint = 0, parentheses_length = 0, i = 0;
    for (; i < substr.length(); i++) {
      if (substr[i] == '(') {
        checkpoint += 1;
      } else {
        checkpoint -= 1;
        if (checkpoint == 0) parentheses_length =
          ((i + 1) > parentheses_length) ? (i + 1) : parentheses_length;
      }
      if (checkpoint < 0) break;
    }
    if (parentheses_length > 0) {
      pos += parentheses_length;
    } else {
      pos += 1;
    }
    spdlog::info("pos: {} length: {}", pos, parentheses_length);
    output = std::make_pair(parentheses_length, pos);
    return output;
  }
 public:
  int longestValidParentheses(std::string s) {
    int len = s.length();
    if (len < 2) return 0;
    std::vector<std::pair<int, int>> dp(len, std::pair<int, int>(0, 0));
    for (int i = 0; i < len;) {
      std::pair<int, int> inner = checkparentheses(i, s.substr(i));
      dp[i] = inner;
      i = inner.second;
    }
    int longest_n = 0;
    for (auto iter : dp) {
      longest_n = (iter.first > longest_n) ? iter.first : longest_n;
    }
    return longest_n;
  }
};