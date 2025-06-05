#include <Span.hpp>
#include <iostream>
#include <algorithm>

int main(void)
{
	{
		std::cout << "\nTEST 01 -- Subject\n";

		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << "longest: " << sp.longestSpan() << std::endl;
			std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}

	{
		std::cout << "\nTEST 02 -- Error\n";

		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			sp.addNumber(11); //ERROR

			std::cout << "longest: " << sp.longestSpan() << std::endl;
			std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}

	{
		std::cout << "\nTEST 03 -- Very, very much so\n";
		
		try
		{
			unsigned int max = 100000;
			std::vector<int> v(max);
			Span sp = Span(max);
	
			srand(time(0));
			std::generate(v.begin(), v.end(), rand);

			sp.addNumber(v.begin(), v.end());

			std::cout << "longest: " << sp.longestSpan() << std::endl;
			std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}

	return (0);
}