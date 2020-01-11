/**
 *  @file    maxDepth.hpp
 *  @brief   LeetCode problems 104: find the max depth of binary tree
 *  @author  ppeng
 *  @date    2020-01-09
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "extend.hpp"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
 public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int depth = 1;
    depth += std::max(maxDepth(root->left), maxDepth(root->right));
    return depth;
  }
};