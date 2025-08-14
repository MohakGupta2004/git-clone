#include <filesystem>
#include <fstream>
#include <iostream>

#ifndef COMMANDS_H
#define COMMANDS_H
class Commands {
private:
  std::ofstream outputFile;

public:
  Commands(std::ofstream &_outFile);
  void initialize();
};
#endif
