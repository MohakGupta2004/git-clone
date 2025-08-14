#include "commands.h"
#include <filesystem>
#include <fstream>
#include <iostream>

Commands::Commands(std::ofstream &_outFile) {
  outputFile = std::move(_outFile);
}
void Commands::initialize() {
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
