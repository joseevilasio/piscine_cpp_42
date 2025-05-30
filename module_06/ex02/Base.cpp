#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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

}

void	identify(Base* p)
{

}

void	identify(Base& p)
{

}
