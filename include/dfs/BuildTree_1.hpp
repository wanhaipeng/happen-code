/**
 *  @file    BuildTree_1.hpp
 *  @brief   LeetCode problems 106: construct the binary tree with inorder traversal and postorder traversal
 *  @author  ppeng
 *  @date    2020-01-10
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
  void buildTree_inner(TreeNode*& node, vector<int>& postorder, vector<int>& subtree) {
    int val = *postorder.rbegin();
    node = new TreeNode(val);
    postorder.pop_back();
    int pos = order_split(subtree, val);
    // build right subtree
    vector<int> right_subtree(subtree.begin() + pos + 1, subtree.end());
    if (!right_subtree.empty()) {
      buildTree_inner(node->right, postorder, right_subtree);
    }
    // build left subtrjee
    vector<int> left_subtree(subtree.begin(), subtree.begin() + pos);
    if (!left_subtree.empty()) {
      buildTree_inner(node->left, postorder, left_subtree);
    }
    return;
  }
  int order_split(vector<int>& order, int val) {
    vector<int>::iterator iter = std::find(order.begin(), order.end(), val);
    return std::distance(order.begin(), iter);
  }
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* head = NULL;
    // process boundary condition
    if (inorder.empty() || postorder.empty()) {
      return head;
    }
    // init head node
    int val = *postorder.rbegin();
    head = new TreeNode(val);
    postorder.pop_back();
    // get inorder split pos
    int pos = order_split(inorder, val);
    // build right subtree
    vector<int> right_subtree(inorder.begin() + pos + 1, inorder.end());
    if (!right_subtree.empty()) {
      buildTree_inner(head->right, postorder, right_subtree);
    }
    // build left subtree
    vector<int> left_subtree(inorder.begin(), inorder.begin() + pos);
    if (!left_subtree.empty()) {
      buildTree_inner(head->left, postorder, left_subtree);
    }
    return head;
  }
};