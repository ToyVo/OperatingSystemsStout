#include <iostream>
#include <stdio.h>
#include <string>

int main() {
  std::string cmd;

  while (true) {
    std::cout << "> ";
    std::getline(std::cin, cmd);
    if (cmd == "exit") {
      break; // in case we need to do cleanup before exit
    } else if (cmd == "history") {
      std::cout << "history" << std::endl;
    } else if (cmd == "pwd") {
      std::cout << "pwd" << std::endl;
    }
  }
}