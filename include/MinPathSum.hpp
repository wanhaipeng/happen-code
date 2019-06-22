/** @file    MinPathSum.hpp
 *  @brief   LeetCode problems 64: MinPathSum implementation
 *  @author  ppeng
 *  @date    2019-06-15
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "extend.hpp"

class Solution {
 private:
  std::vector<int> range(int n) {
    std::vector<int> data;
    for (int i = 0; i < n; i++) {
      data.emplace_back(i);
    }
    return std::move(data);
  }
 public:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
    for (int i : range(rows)) {
      for (int j : range(cols)) {
        if (i == 0 && j == 0) {
          dp[i][j] = grid[i][j];
        } else if (i == 0 && j > 0) {
          dp[i][j] = grid[i][j] + dp[i][j-1];
        } else if (j == 0 && i > 0) {
          dp[i][j] = grid[i][j] + dp[i-1][j];
        } else {
          dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
      }
    }
    return dp[rows-1][cols-1];
  }
};