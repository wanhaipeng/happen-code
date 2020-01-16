/**
 *  @file    MinDepth.hpp
 *  @brief   LeetCode problems 111: find the min depth from root to leaf node
 *  @author  ppeng
 *  @date    2020-01-13
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

class Solution {
 private:
  int minDepth_inner(TreeNode* node) {
    if (node == NULL) { return 0; }
    if (node->left == NULL && node->right == NULL) { return 1; }
    if (node->left == NULL) {
      return minDepth_inner(node->right) + 1;
    } else if (node->right == NULL) {
      return minDepth_inner(node->left) + 1;
    } else {
      return (std::min(minDepth_inner(node->left), minDepth_inner(node->right)) + 1);
    }
  }
 public:
  int minDepth(TreeNode* root) {
    // process boundary condition
    if (root == NULL) { return 0; }
    if (root->left == NULL && root->right == NULL) { return 1; }
    // init status
    int min_depth;
    if (root->left == NULL) {
      min_depth = minDepth_inner(root->right) + 1;
    } else if (root->right == NULL) {
      min_depth = minDepth_inner(root->left) + 1;
    } else {
      min_depth = std::min(minDepth_inner(root->left), minDepth_inner(root->right)) + 1;
    }
    return min_depth;
  }
};