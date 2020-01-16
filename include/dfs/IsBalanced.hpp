/**
 *  @file    IsBalanced.hpp
 *  @brief   LeetCode problems 110: judge whether the binary tree is balanced
 *  @author  ppeng
 *  @date    2020-01-13
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
 private:
  bool isBalanced_inner(TreeNode* node, int& node_depth) {
    if (node == NULL) {
      node_depth = 0;
      return true;
    }
    bool left_balanced, right_balanced;
    int left_depth, right_depth;
    left_balanced = isBalanced_inner(node->left, left_depth);
    right_balanced = isBalanced_inner(node->right, right_depth);
    if (left_balanced && right_balanced) {
      if (abs(left_depth - right_depth) <= 1) {
        node_depth = std::max(left_depth, right_depth) + 1;
        return true;
      }
    }
    return false;
  }
 public:
  bool isBalanced(TreeNode* root) {
    // process boundary condition
    if (root == NULL) { return true; }
    if (root->left == NULL && root->right == NULL) { return true; }
    bool is_left_balanced, is_right_balanced;
    int l_depth = 1, r_depth = 1;
    // check left subtree
    is_left_balanced = isBalanced_inner(root->left, l_depth);
    // check right subtree
    is_right_balanced = isBalanced_inner(root->right, r_depth);
    if (is_left_balanced && is_right_balanced) {
      if (abs(l_depth - r_depth) <= 1) { 
        return true;
      }
    }
    return false;
  }
};