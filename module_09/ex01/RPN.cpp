#include "RPN.hpp"

RPN::RPN(void) {}

RPN::~RPN(void) {}

void RPN::insert(int n)
{
    _stack.push(n);
}

void RPN::remove()
{
    // if (_stack.empty())
    //     std::cout << "empty\n";
    // _stack.pop();
    std::cout << _stack.top() << std::endl;
}
