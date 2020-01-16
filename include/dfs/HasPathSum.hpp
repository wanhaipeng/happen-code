/**
 *  @file    HaspathSum.hpp
 *  @brief   LeetCode problems 112: judge whether is there a path sum equals val
 *  @author  ppeng
 *  @date    2020-01-14
 */
#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
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
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    // process boundary condition
    if (root == NULL) { return false; }
    // process recursive
    int val = root->val;
    int next_status = sum - val;
    if (root->left == NULL && root->right == NULL && next_status == 0) { return true; }
    if (hasPathSum(root->left, next_status) || hasPathSum(root->right, next_status)) { return true; }
    return false;
  }
};