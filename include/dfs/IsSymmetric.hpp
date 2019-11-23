/**
 *  @file    IsSymmetric.hpp
 *  @brief   LeetCode problems 101: check the binary tree whether is symmetric
 *  @author  ppeng
 *  @date    2019-11-24
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
  bool check_inner(TreeNode* treeA, TreeNode* treeB) {
    if (treeA != NULL && treeB != NULL) {
      if (treeA->val == treeB->val) {
        return (check_inner(treeA->left, treeB->right) &&
                check_inner(treeA->right, treeB->left));
      } else {
        return false;
      }
    } else if (treeA == NULL && treeB == NULL) {
      return true;
    } else {
      return false;
    }
  }
 public:
  bool isSymmetric(TreeNode* root) {
    TreeNode* root_symmetric = root;
    bool is_symmetric = check_inner(root, root_symmetric);
    return is_symmetric;
  }
};