#include "MaxSubarray.hpp"

int main(int argc, char* argv[]) {
  spdlog::set_pattern("[%^%l%$] %v");
  Solution test;
  std::vector<int> input;
  int temp_data;
  while (std::cin >> temp_data) {
    input.push_back(temp_data);
  }
  spdlog::info("input array: [{}]", fmt::join(input, ","));
  int output  = test.maxSubArray(input);
  spdlog::info("output max_value: {}", output);
}