/** @file    MinDistance.hpp
 *  @brief   LeetCode problems 72:  minDistance implementation
 *  @author  ppeng
 *  @date    2019-06-23
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "extend.hpp"

// zoologicoarchaeologist zoogeologist
// kitten sitting

class Solution {
  public:
  int minDistance_e(std::string word1, std::string word2) {
    const int length_m = word1.length();
    const int length_o = word2.length();
    // + 1 for "" match "" distance 0 -> (add bounding)
    std::vector<std::vector<int>> dp(length_m + 1, std::vector<int>(length_o + 1, 0));
    // bounding process
    if (!length_o || !length_m) {
      return std::max(length_m, length_o);
    }
    // calculate distance
    // now position word1[pos_m]: x, word2[pos_o]: y
    int pos_m = 1, pos_o = 1;
    dp.at(pos_m).at(pos_o) = 0;
    for (; pos_m <= length_m && pos_o <= length_o; pos_m++, pos_o++) {
      if (word1.at(pos_m - 1) == word2.at(pos_o - 1)) { // x == y
        dp.at(pos_m).at(pos_o) = dp.at(pos_m - 1).at(pos_o - 1);
      } else { // x != y
        dp.at(pos_m).at(pos_o) = dp.at(pos_m - 1).at(pos_o - 1) + 1; // replace
        if (pos_m < length_m && word1.at(pos_m) == word2.at(pos_o - 1)) {
          pos_m += 1; // rm char && fill with pos_m
          dp.at(pos_m).at(pos_o) = dp.at(pos_m - 1).at(pos_o);
        }
        if (pos_o < length_o && word1.at(pos_m - 1) == word2.at(pos_o)) {
          pos_o += 1; // insert char fill with pos_o - 1
          dp.at(pos_m).at(pos_o) = dp.at(pos_m).at(pos_o - 1);
        }
      }
      spdlog::info("{}-{}: {}", pos_m, pos_o, dp.at(pos_m).at(pos_o));
    }
    // insert or rm
    const int m_offset = length_m - (pos_m - 1);
    const int o_offset = length_o - (pos_o - 1);
    int add_op_num = std::max(o_offset, m_offset);
    spdlog::info("{} {}", m_offset, o_offset);
    dp.at(length_m).at(length_o) = dp.at(pos_m - 1).at(pos_o - 1) + add_op_num;
    return dp.at(length_m).at(length_o);
  }
  int minDistance(std::string word1, std::string word2) {
    const int length_m = word1.length();
    const int length_o = word2.length();
    std::vector<std::vector<int>> dp(length_m, std::vector<int>(length_o, 0));
    // bounding process
    if (!length_o || !length_m) {
      return std::max(length_m, length_o);
    }
    bool first_pos_o = true; // for word1[pos_m] == word2[0]
    bool first_pos_m = true; // for word2[0] == word2[pos_o]
    for (int pos_m = 0; pos_m < length_m; pos_m++) {
      for (int pos_o = 0; pos_o < length_o; pos_o++) {
        if (pos_m == 0 && pos_o == 0) {
          dp.at(pos_m).at(pos_o) = (word1.at(pos_m) == word2.at(pos_o)) ? 0 : 1;
          first_pos_o = (word1.at(pos_m) == word2.at(pos_o)) ? false : true;
          first_pos_m = (word1.at(pos_m) == word2.at(pos_o)) ? false : true;
        } else if (pos_m == 0) {
          if (word1.at(pos_m) == word2.at(pos_o) && first_pos_m) {
            dp.at(pos_m).at(pos_o) = dp.at(pos_m).at(pos_o - 1);
            first_pos_m = false;
          } else {
            dp.at(pos_m).at(pos_o) = dp.at(pos_m).at(pos_o - 1) + 1;
          }
        } else if (pos_o == 0) {
          if (word1.at(pos_m) == word2.at(pos_o) && first_pos_o) {
            dp.at(pos_m).at(pos_o) = dp.at(pos_m - 1).at(pos_o);
            first_pos_o = false;
          } else {
            dp.at(pos_m).at(pos_o) = dp.at(pos_m - 1).at(pos_o) + 1;
          }
        } else {
          if (word1.at(pos_m) == word2.at(pos_o)) {
            dp.at(pos_m).at(pos_o) =
              dp.at(pos_m - 1).at(pos_o - 1);
          } else {
            dp.at(pos_m).at(pos_o) =
              std::min(dp.at(pos_m - 1).at(pos_o), std::min(dp.at(pos_m - 1).at(pos_o - 1), dp.at(pos_m).at(pos_o - 1))) + 1;
          }
        }
      }
    }
    for (auto iter : dp) {
      spdlog::info("[{}]", fmt::join(iter, ","));
    }
    // calculate distance
    return dp.at(length_m - 1).at(length_o - 1);
  }
};