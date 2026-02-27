#include <iostream>

int main() {
  std::string space = " ";
  std::string star = "*";
  int row;
  int column;
  std::cout << "Enter row num: ";
  std::cin >> row;
  column = 1 + (row - 1) * 2;
  int starCount = 1;
  for (int a = column / 2; a >= 0; a--) {
    for (int b = 0; b < a; b++) {
      std::cout << space;
    }
    for (int c = 0; c < starCount; c++) {
      std::cout << star;
    }
    starCount += 2;
    std::cout << "\n";
  }

  return 0;
}