#include "src/commands.h"
#include <fstream>
#include <iostream>
int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: git init for initializing a git repository."
              << std::endl;
  }

  std::string command = argv[1];
  std::ofstream outputFile;
  Commands commands(outputFile);
  if (command == "init") {
    commands.initialize();
  } else {
    std::cout << "Unknown command: " << command << std::endl;
  }
}
