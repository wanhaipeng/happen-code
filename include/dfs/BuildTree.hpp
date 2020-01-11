/**
 *  @file    BuildTree.hpp
 *  @brief   LeetCode problems 105: construct the binary tree with preorder traversal and middle order traversal
 *  @author  ppeng
 *  @date    2020-01-09
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
  int split_set(vector<int>& order, int val) {
    vector<int>::iterator iter = std::find(order.begin(), order.end(), val);
    int idx = std::distance(order.begin(), iter);
    return idx;
  }
  void buildTree_inner(TreeNode*& node, vector<int>::iterator& preorder_iter, vector<int>& subtree) {
    node = new TreeNode(*preorder_iter);
    // spdlog::info("build node: {}", *preorder_iter);
    int idx = split_set(subtree, *preorder_iter);
    preorder_iter++;
    // build left subtree
    vector<int> left_subtree(subtree.begin(), subtree.begin() + idx);
    if (!left_subtree.empty()) {
      buildTree_inner(node->left, preorder_iter, left_subtree);
    }
    // build right subtree
    vector<int> right_subtree(subtree.begin() + idx + 1, subtree.end());
    if (!right_subtree.empty()) {
      buildTree_inner(node->right, preorder_iter, right_subtree);
    }
    return;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // process boundary condition
    if (preorder.empty() && inorder.empty()) {
      return nullptr;
    }
    // create head point
    vector<int>::iterator preorder_iter = preorder.begin();
    TreeNode* head = new TreeNode(*preorder_iter);
    // spdlog::info("build node: {}", *preorder_iter);
    int idx = split_set(inorder, *preorder_iter);
    preorder_iter++;
    // build left subtree
    vector<int> left_subtree(inorder.begin(), inorder.begin() + idx);
    if (!left_subtree.empty()) {
      buildTree_inner(head->left, preorder_iter, left_subtree);
    }
    // builf right subtree
    vector<int> right_subtree(inorder.begin() + idx + 1, inorder.end());
    if (!right_subtree.empty()) {
      buildTree_inner(head->right, preorder_iter, right_subtree);
    } 
    return head;
  }
};