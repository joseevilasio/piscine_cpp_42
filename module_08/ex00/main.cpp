#include <easyfind.hpp>
#include <vector>
#include <list>
#include <iostream>

int main(void)
{
	{
		std::cout << "\n TEST 01 - Vector\n";

		std::vector<int> v;
	
		v.push_back(42);
		v.push_back(22);
		v.push_back(12);
		v.push_back(2);
	
		try
		{
			std::cout << "Value: " << easyfind(v, 42) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n TEST 02 - List\n";
		
		std::list<int> l;
	
		l.push_back(42);
		l.push_back(22);
		l.push_back(12);
		l.push_back(2);
	
		try
		{
			std::cout << "Value: " << easyfind(l, 12) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}