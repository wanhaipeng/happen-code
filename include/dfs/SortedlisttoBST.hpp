/**
 *  @file    SortedlisttoBST.hpp
 *  @brief   LeetCode problems 109: build binary balanced search tree with sorted list
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

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 private:
  void toBST_inner(TreeNode*& node, ListNode* lb, ListNode* rb) {
    // process boundary condition
    if (lb == rb) {
      node = new TreeNode(lb->val);
      // spdlog::info("build node -> {}", lb->val);
      return;
    }
    if (rb->next == lb) return;
    // process normal
    ListNode* fast = lb;
    ListNode* slow = lb;
    ListNode* slow_pre = lb;
    while (fast != rb) {
      slow_pre = slow;
      slow = slow->next;
      fast = fast->next;
      if (fast == rb) break;
      fast = fast->next;
    }
    node = new TreeNode(slow->val);
    // spdlog::info("build node -> {}", slow->val);
    // build left subtree
    ListNode* ll = lb;
    ListNode* lr = slow_pre;
    if (ll != NULL && lr != NULL) {
      toBST_inner(node->left, ll, lr);
    }
    // build right subtree
    ListNode* rl = slow->next;
    ListNode* rr = rb;
    if (rl != NULL && rr != NULL) {
      toBST_inner(node->right, rl, rr);
    }
    return;
  }
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    TreeNode* bst_head;
    // process boundary condition
    if (head == NULL) { return bst_head = NULL;}
    if (head->next == NULL) {return bst_head = new TreeNode(head->val); }
    // init head node: find middle point in list
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* slow_pre = head;
    while (fast->next != NULL) {
      slow_pre = slow;
      slow = slow->next;
      fast = fast->next;
      if (fast->next == NULL) break;
      fast = fast->next;
    }
    bst_head = new TreeNode(slow->val);
    // spdlog::info("build node -> {}", slow->val);
    // build left subtree
    ListNode* ll = head;
    ListNode* lr = slow_pre;
    if (ll != NULL && lr != NULL) {
      toBST_inner(bst_head->left, ll, lr);
    }
    // build right subtree
    ListNode* rl = slow->next;
    ListNode* rr = fast;
    if (rl != NULL && rr != NULL) {
      toBST_inner(bst_head->right, rl, rr);
    }
    return bst_head;
  }
};