#include "LongestValidParentheses.hpp"

int main(int argc, char* argv[]) {
  spdlog::set_pattern("[%^%l%$] %v");
  Solution test;
  std::string input;
  std::cin >> input;
  spdlog::info("input: {}", input);
  int output  = test.longestValidParentheses(input);
  spdlog::info("output max_value: {}", output);
}
