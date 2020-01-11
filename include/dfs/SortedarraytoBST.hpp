/**
 *  @file    SortedarraytoBST.hpp
 *  @brief   LeetCode problems 108: build binary balanced search tree
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
   void toBST_inner(TreeNode*& node, vector<int>& nums, int lb, int rb) {
     int in_node_pos = std::floor((lb + rb) / 2);
     int in_node_val = nums[in_node_pos];
     node = new TreeNode(in_node_val);
     // spdlog::info("build node -> {}", in_node_val);
     // build left subtree
     int lsub_lb = lb, lsub_rb = in_node_pos - 1;
     if (lsub_lb <= lsub_rb) {
       toBST_inner(node->left, nums, lsub_lb, lsub_rb);
     }
     // build right subtree
     int rsub_lb = in_node_pos + 1, rsub_rb = rb;
     if (rsub_lb <= rsub_rb) {
       toBST_inner(node->right, nums, rsub_lb, rsub_rb);
     }
     return;
   }
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* head;
    if (nums.empty()) { return head = NULL; }
    int in_node_l = 0, in_node_r = nums.size() - 1;
    int in_node_pos = std::floor((in_node_l + in_node_r) * 1.0 / 2);
    int in_node_val = nums[in_node_pos];
    head = new TreeNode(in_node_val);
    // spdlog::info("build node -> {}", in_node_val);
    // build left subtree
    int left_subtree_l = in_node_l, left_subtree_r = in_node_pos - 1;
    if (left_subtree_l <= left_subtree_r) {
      toBST_inner(head->left, nums, left_subtree_l, left_subtree_r);
    }
    // build right subtree
    int right_subtree_l = in_node_pos + 1, right_subtree_r = in_node_r;
    if (right_subtree_l <= right_subtree_r) {
      toBST_inner(head->right, nums, right_subtree_l, right_subtree_r);
    }
    return head;
  }
};