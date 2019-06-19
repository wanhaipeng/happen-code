#include "IsMatch.hpp"

int main(int argc, char* argv[]) {
  spdlog::set_pattern("[%^%l%$] %v");
  Solution test;
  std::string str;
  std::string pattern;
  std::cin >> str;
  std::cin >> pattern;
  spdlog::info("input str: {} pattern: {}", str, pattern);
  bool output  = test.isMatch(str, pattern);
  spdlog::info("ismatch: {}", output);
}
