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

		void	getIdea(int index) const;
		void	setIdea(int index, std::string idea)
};

#endif //BRAIN_HPP