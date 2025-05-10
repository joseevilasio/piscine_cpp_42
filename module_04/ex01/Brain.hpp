#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain& operator=(const Brain& rhs);
		Brain(const Brain& rhs);
		~Brain(void);
};

#endif //BRAIN_HPP