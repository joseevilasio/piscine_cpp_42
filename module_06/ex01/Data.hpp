#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data
{
	std::string _name;
	int _age;

	Data(const std::string& name, int age);
};

#endif //DATA_HPP