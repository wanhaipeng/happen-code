#include "LongestPalindromeSubstring.hpp"

int main(int argc, char* argv[]) {
  spdlog::set_pattern("[%^%l%$] %v");
  Solution test;
  std::string input;
  getline(std::cin, input);
  spdlog::info("input string: {}", input);
  std::string output  = test.longestPalindrome(input);
  spdlog::info("output substring: {}", output);
}