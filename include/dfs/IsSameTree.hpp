/**
 *  @file    IsSameTree.hpp
 *  @brief   LeetCode problems 100: check the two binary tree whether same
 *  @author  ppeng
 *  @date    2019-11-23
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
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p != NULL && q != NULL) {
      if (p->val == q->val) {
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
      } else {
        return false;
      }
    } else if (p == NULL && q == NULL) {
      return true;
    } else {
      return false;
    }
  }
};