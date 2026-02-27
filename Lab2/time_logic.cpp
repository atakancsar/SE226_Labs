#include <iostream>
#include <ostream>

int main() {
  int seconds;
  std::cout << "Enter second: ";
  std::cin >> seconds;
  std::cout << "\n";

  int minutes = seconds / 60;
  int hours = minutes / 60;

  std::cout << "Hours: " << hours << " Minutes:" << minutes
            << " Seconds:" << seconds;

  return 0;
}