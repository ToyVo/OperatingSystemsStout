#include "shell.hpp"
#include <iostream>
#include <string>

int main() {
  std::string cmd;

  while (true) {
    std::cout << getenv("USER") << " > ";
    std::getline(std::cin, cmd);
    write_history(cmd);
    if (cmd == "exit") {
      break;
    } else if (cmd == "history") {
      read_history();
    } else if (cmd == "pwd") {
      std::cout << getenv("PWD") << "\n";
    }
  }

  return 0;
}
