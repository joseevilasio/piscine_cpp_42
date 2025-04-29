#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>

bool		ensureValidArguments(int argc, char **argv);
bool		ensureValidFilestream(std::ifstream& file);
std::string	defaultOutputName(std::string& filename);

#endif //UTILS_H