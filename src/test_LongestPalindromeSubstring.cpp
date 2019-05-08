#include "LongestPalindromeSubstring.hpp"

int main(int argc, char* argv[]) {
  Solution test;
  string input;
  getline(cin, input);
  cout << "input string: " << input << endl;
  string output  = test.longestPalindrome(input);
  cout << "output substring: " << output << endl;
}