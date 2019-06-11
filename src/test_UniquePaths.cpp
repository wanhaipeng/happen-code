#include "UniquePaths.hpp"

int main(int argc, char* argv[]) {
  spdlog::set_pattern("[%^%l%$] %v");
  Solution test;
  int m, n;
  std::cin >> m >> n;
  spdlog::info("input m: {} n: {}", m, n);
  int output  = test.uniquePaths(m, n);
  spdlog::info("output max_value: {}", output);
}
