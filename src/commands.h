#include <filesystem>
#include <fstream>
#include <iostream>

#ifndef COMMANDS_H
#define COMMANDS_H
class Commands {
private:
  std::ofstream outputFile;

public:
  Commands(std::ofstream &_outFile) { outputFile = std::move(_outFile); }
  void initialize() {
    try {
      std::filesystem::create_directory(".git");
      std::filesystem::create_directory(".git/objects");
      std::filesystem::create_directory(".git/refs");
      std::filesystem::create_directory(".git/refs/heads");
      outputFile.open(".git/HEAD");
      if (outputFile.is_open()) {
        std::cout << "initializing git repository" << std::endl;
        outputFile << "ref: refs/heads/main" << std::endl;
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
};

#endif
