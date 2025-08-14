#include <filesystem>
#include <fstream>
#include <iostream>
int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: git init for initializing a git repository."
              << std::endl;
  }

  std::string command = argv[1];
  std::ofstream outputFile;
  if (command == "init") {
    try {
      std::filesystem::create_directory(".git");
      std::filesystem::create_directory(".git/objects");
      std::filesystem::create_directory(".git/refs");
      std::filesystem::create_directory(".git/refs/heads");
      outputFile.open(".git/HEAD");
      if (outputFile.is_open()) {
        std::cout << "initializing git repository" << std::endl;
        outputFile << "ref: refs/heads/master" << std::endl;
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  } else {
    std::cout << "Unknown command: " << command << std::endl;
  }
}
