#include <iostream>

int main() {
  std::string name;
  int id;

  std::cout << "What is your name? ";
  std::cin >> name;
  std::cout << "\n" << "Hello " << name;
  std::cout << "\n" << "What is your id? ";
  std::cin >> id;
  std::cout << "\n" << "Your ID is " << id;

  return 0;
}