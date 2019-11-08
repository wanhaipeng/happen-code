/**
 *  @file    IsvalidBST.cpp
 *  @brief   LeetCode problems 98: isvalid binray search tree implementation
 *  @author  ppeng
 *  @date    2019-11-05
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
  bool checkwithstack(TreeNode* node) {
    double val = -__DBL_MAX__;
    std::stack<TreeNode*> tree;
    while (!tree.empty() || node != NULL) {
      while (node != NULL) {
        tree.push(node);
        node = node->left;
      }
      node = tree.top();
      tree.pop();
      if (node->val <= val) return false;
      val = node->val;
      node = node->right;
    }
    return true;
  }
 public:
  bool isValidBST(TreeNode* root) {
    if (root == NULL) {
      return true;
    }
    bool result = checkwithstack(root);
    return result;
  }
};
