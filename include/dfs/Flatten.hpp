/**
 *  @file    xxxxxx.hpp
 *  @brief   LeetCode problems xx: xxx
 *  @author  ppeng
 *  @date    2020-01-15
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "extend.hpp"

using std::vector;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};