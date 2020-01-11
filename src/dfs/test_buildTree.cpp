#include "BuildTree.hpp"

int main(int argc, char* argv[]) {
  spdlog::set_pattern("[%^%l%$] %v");
  // init preorder and inorder
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  // test buildTree
  Solution test;
  test.buildTree(preorder, inorder);
  return 0;
}
