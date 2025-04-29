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
std::string	handleReplace(std::string line, std::string& str1, std::string& str2);

#endif //UTILS_H