/** @file    UniquePathsWithObstacles.hpp
 *  @brief   LeetCode problems 63: UniquePathsWithObstacles implementation
 *  @author  ppeng
 *  @date    2019-06-12
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
  int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    // init dp array && set value by obstacleGrid
    std::vector<std::vector<long>> dp(row, std::vector<long>(col, 0));
    for (int i : range(row)) {
      for (int j : range(col)) {
        if (i == 0 && j == 0) { // set [0][0]
          dp[i][j] = (obstacleGrid[i][j] == 0) ? 1 : 0;
        } else if (i == 0 && j > 0) { // set [0][j]
          dp[i][j] = (obstacleGrid[i][j] == 0) ? dp[i][j-1] : 0;
        } else if (i > 0 && j == 0) { // set [i][0]
          dp[i][j] = (obstacleGrid[i][j] == 0) ? dp[i - 1][j] : 0;
        } else { // set[i][j]
          dp[i][j] = (obstacleGrid[i][j] == 0) ? (dp[i-1][j] + dp[i][j-1]) : 0;
        }
      }
    }
    return dp[row - 1][col - 1];
  }
};