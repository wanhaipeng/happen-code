/**
 *  @file    RecoverTree.hpp
 *  @brief   LeetCode problems 99: recover binary search tree
 *  @author  ppeng
 *  @date    2019-11-11
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
  void recoverTree(TreeNode* root) {
    std::stack<TreeNode*> tmpstack;
    TreeNode* searchnode = root;
    TreeNode* prenode = NULL;
    TreeNode* beginnode = NULL;
    TreeNode* endnode = NULL;
    bool pre_flag = false;
    int tmpvalue = 0;
    while(!tmpstack.empty() || searchnode != NULL) {
      while(searchnode != NULL) {
        tmpstack.push(searchnode);
        searchnode = searchnode->left;
      }
      searchnode = tmpstack.top();
      tmpstack.pop();
      if (!pre_flag) {
        tmpvalue = searchnode->val;
        prenode = searchnode;
        pre_flag = true;
      } else {
        if (searchnode->val <= tmpvalue) {
          if (beginnode == NULL) { beginnode = prenode; }
          endnode = searchnode;
          prenode = searchnode;
        }
        prenode = searchnode;
        tmpvalue = searchnode->val;
      }
      searchnode = searchnode->right;
    }
    if (beginnode != NULL && endnode != NULL) {
      tmpvalue = beginnode->val;
      beginnode->val = endnode->val;
      endnode->val = tmpvalue;
    }
  }
};
