/**
 *  @file    Flatten.hpp
 *  @brief   LeetCode problems 114: flatten the binary tree
 *  @author  ppeng
 *  @date    2020-01-15
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
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
 public:
  void flatten(TreeNode* root) {
    // process boundary condition
    if (root == NULL) { return; }
    std::stack<TreeNode*> treestack;
    TreeNode* list = NULL;
    TreeNode* inner = NULL;
    treestack.push(root);
    while (!treestack.empty()) {
      inner = treestack.top();
      treestack.pop();
      if (inner->right != NULL) treestack.push(inner->right);
      if (inner->left != NULL) treestack.push(inner->left);
      // build list
      if (list == NULL) {
        list = inner;
      } else {
        list->right = inner;
        list->left = NULL;
        list = inner;
      }
    }
  }
};
