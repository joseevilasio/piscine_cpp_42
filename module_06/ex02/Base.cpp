#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base::Base(void) {}

Base::~Base(void) {}

Base*	Base::makeA(void)
{
	return (new A());
}

Base*	Base::makeB(void)
{
	return (new B());
}

Base*	Base::makeC(void)
{
	return (new C());
}

Base*	generate(void)
{
	Base* (Base::*baseFactory[3])() = {
		&Base::makeA,
		&Base::makeB,
		&Base::makeC
	};

	int i = 1 + rand() % 3;
	return ((this->*baseFactory[i])());
}

// void	identify(Base* p)
// {

// }

// void	identify(Base& p)
// {

// }
