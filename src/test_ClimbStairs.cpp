#include "ClimbStairs.hpp"

int main(int argc, char* argv[]) {
  spdlog::set_pattern("[%^%l%$] %v");
  Solution test;
  int n;
  std::cin >> n;
  spdlog::info("input n: {}", n);
  int output  = test.climbStairs(n);
  spdlog::info("output climb methods: {}", output);
}
