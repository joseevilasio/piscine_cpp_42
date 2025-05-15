#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource& operator=(const MateriaSource& rhs);
		MateriaSource(const MateriaSource& rhs);
		~MateriaSource() {}
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif //MATERIA_SOURCE_HPP