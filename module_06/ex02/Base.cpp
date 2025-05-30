#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::Base(void) {}

Base::~Base(void) {}

Base*	generate(void)
{
	int i = rand() % 3;

	switch (i)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void	identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A\n";
	}
	catch(...)
	{
		try
		{
			(void) dynamic_cast<B&>(p);
			std::cout << "B\n";
		}
		catch(...)
		{
			try
			{
				(void) dynamic_cast<C&>(p);
				std::cout << "C\n";
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
		}
	}
}
