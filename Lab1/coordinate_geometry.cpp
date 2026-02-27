#include <cmath>
#include <iostream>

int main() {
  int x1, x2, y1, y2;
  std::cout << "Enter x1, y1, x2, y2: ";
  std::cin >> x1 >> y1 >> x2 >> y2;

  double distance = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
  std::cout << "Distance: " << distance << "\n";

  return 0;
}