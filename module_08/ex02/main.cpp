#include "MutantStack.hpp"
#include <list>
#include <vector>

// int main(void)
// {
// 	MutantStack<int>	mstack;

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << mstack.top() << std::endl;

// 	mstack.pop();

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(7);
// 	mstack.push(77);
// 	mstack.push(70);
// 	mstack.push(1);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();

// 	++it;
// 	--it;

// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}

// 	std::stack<int> s(mstack);

// 	return (0);
// }

int	main(void)
{
		MutantStack<int>	mstack;
		std::list<int>		list;
		std::vector<int>	v;

		mstack.push(10);
		mstack.push(20);
		mstack.push(30);
		mstack.push(40);
		mstack.push(50);


		list.push_back(10);
		list.push_back(20);
		list.push_back(30);
		list.push_back(40);
		list.push_back(50);

		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);
		v.push_back(50);

		mstack.pop();
		list.pop_back();
		v.pop_back();

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::list<int>::iterator l_it = list.begin();
		std::vector<int>::iterator v_it = v.begin();

		while (it != ite)
		{
			std::cout << "mstack : " << *it << std::endl;
			std::cout << "list   : " << *l_it << std::endl;
			std::cout << "vector : " << *v_it << std::endl;
			std::cout << std::endl;
			++it;
			++l_it;
			++v_it;
		}
		return (0);
}