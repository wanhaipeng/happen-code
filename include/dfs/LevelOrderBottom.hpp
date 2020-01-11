/**
 *  @file    LevelOrderBottom.hpp
 *  @brief   LeetCode problems 107: left->right, bottom->top traversal
 *  @author  ppeng
 *  @date    2020-01-11
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
  void traversal_tree(TreeNode* node, vector<vector<int>>& levelorder, int level) {
    if (levelorder.size() < level) {
      vector<int> inner_level = {node->val};
      levelorder.emplace_back(inner_level);
    } else {
      levelorder[level - 1].emplace_back(node->val);
    }
    // traversal left
    if (node->left != NULL) {
      traversal_tree(node->left, levelorder, level + 1);
    }
    // traversal left
    if (node->right != NULL) {
      traversal_tree(node->right, levelorder, level + 1);
    }
    return;
  }
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> levelorder;
    if (root == NULL) {
      return levelorder;
    }
    int level = 1;
    traversal_tree(root, levelorder, level);
    // reversal
    std::reverse(levelorder.begin(), levelorder.end());
    return levelorder;
  }
};