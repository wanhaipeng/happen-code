#include "SortedlisttoBST.hpp"

int main(int argc, char* argv[]) {
  spdlog::set_pattern("[%^%l%$] %v");
  // init singly linked list
  vector<int> input = {1,3};
  ListNode* head;
  head = new ListNode(input[0]);
  ListNode* head_ptr = head;
  int pos = 1;
  while(pos < input.size()) {
    head->next = new ListNode(input[pos]);
    head = head->next;
    spdlog::error("happen check in source! {} {} {}", input[pos], head->val, head_ptr->val);
    pos++;
  }
  // test
  Solution test;
  test.sortedListToBST(head_ptr);
  return 0;
}
