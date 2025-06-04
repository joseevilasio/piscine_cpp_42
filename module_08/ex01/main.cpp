#include <Span.hpp>
#include <iostream>

int main(void)
{
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//v.addNumber(50); //error
		//sp.print();
		std::cout << "longest: " << sp.longestSpan() << std::endl;
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (0);
}