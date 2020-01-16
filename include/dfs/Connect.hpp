/**
 *  @file    Connect.hpp
 *  @brief   LeetCode problems 116: set the next pointer of perfect binary tree
 *  @author  ppeng
 *  @date    2020-01-15
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "extend.hpp"

using std::vector;

/**
 * Definition for a binary tree node.
 */
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    // process boundary condition
    if (root == NULL) { return root; }
    // init status
    std::queue<Node*> connect_queue;
    connect_queue.push(root);
    Node* inner;
    int idx = 0, val = 0;
    while(!connect_queue.empty()) {
      inner = connect_queue.front();
      connect_queue.pop();
      idx += 1;
      if (inner->left != NULL) connect_queue.push(inner->left);
      if (inner->right != NULL) connect_queue.push(inner->right);
      if (idx == (2 * val + 1)) { 
        inner->next = NULL;
        val = 2 * val + 1;
      } else {
        inner->next = connect_queue.front();
      }
    }
    return root;
  }
};