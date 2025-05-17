#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_templates[4];

	public:
		MateriaSource(void);
		MateriaSource& operator=(const MateriaSource& rhs);
		MateriaSource(const MateriaSource& rhs);
		~MateriaSource();

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(std::string const & type);
};

#endif //MATERIA_SOURCE_HPP