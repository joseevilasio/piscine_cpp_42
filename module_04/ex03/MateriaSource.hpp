#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <string>
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		virtual ~MateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif //MATERIA_SOURCE_HPP