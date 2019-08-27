/** @file    LongestPalindromeSubstring.hpp
 *  @brief   LeetCode problems 5: LongestPalindromeSubstring implementation
 *  @author  ppeng
 *  @date    2019-05-08
 */
#pragma once
#include <iostream>
#include <string>
#include "extend.hpp"

class Solution {
private:
  std::string output_substr;
public:
  Solution() = default;
  std::string longestPalindrome(std::string s) {
    int input_str_size = s.size();
    if (input_str_size == 0) {
      output_substr = ""; 
      return output_substr; // input empty
    }
    int longest_size = 0;
    for (int i = 0; i < (2 * input_str_size - 1); i++) { // len(substr) % 2 == 1
      int left_ptr = 0, right_ptr = 0;
      // set left/right ptr
      if (i % 2 == 0) {
        left_ptr = i / 2; right_ptr = i / 2;
      } else {
          left_ptr = (i - 1) / 2; right_ptr = (i + 1) / 2;
      }
      // scan string
      for (; left_ptr >= 0 && right_ptr <= (input_str_size - 1); left_ptr--, right_ptr++) {
        if (s[left_ptr] != s[right_ptr]) break;
      }
      left_ptr++; right_ptr--;
      // update output_substr
      if (left_ptr == 0 && right_ptr == (input_str_size - 1)) {
        output_substr = s;
        longest_size = input_str_size;
      } else {
        if ((right_ptr - left_ptr + 1) > longest_size) {
          longest_size = right_ptr - left_ptr + 1;
          output_substr = s.substr(left_ptr, right_ptr - left_ptr + 1);
        }
      }
    }
    return output_substr;
  }
};