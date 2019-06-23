#include "MinDistance.hpp"

int main(int argc, char* argv[]) {
  spdlog::set_pattern("[%^%l%$] %v");
  Solution test;
  std::string word1;
  std::string word2;
  while (std::cin >> word1 >> word2) {
    spdlog::info("input word1: {} word2: {}", word1, word2);
    const int output = test.minDistance(word1, word2);
    spdlog::info("minDistance: {}", output);
  }
  return 0;
}
