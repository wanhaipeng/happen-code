#include "SortedarraytoBST.hpp"

int main(int argc, char* argv[]) {
  spdlog::set_pattern("[%^%l%$] %v");
  // init input
  vector<int> input = {1, 3};
  // test buildTree
  Solution test;
  test.sortedArrayToBST(input);
  return 0;
}
