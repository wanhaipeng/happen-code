/** @file    UniquePaths.cpp
 *  @brief   LeetCode problems 62: UniquePaths implementation
 *  @author  ppeng
 *  @date    2019-06-11
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "extend.hpp"

class Solution {
 private:
  std::vector<int> range(int value) {
    std::vector<int> data;
    for(int i = 0; i < value; i++) {
      data.emplace_back(i);
    }
    return std::move(data);
  }
 public:
  Solution() = default;
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> paths(n, std::vector<int>(m, 0));
    for (int row : range(n)) {
      for (int col : range(m)) {
        if (row == 0 || col == 0) {
          paths[row][col] = 1;
        } else {
          paths[row][col] = paths[row - 1][col] + paths[row][col - 1];
        }
      }
    }
    return paths[n - 1][m - 1];
  }
};
