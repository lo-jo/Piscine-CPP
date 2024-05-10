#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "lib.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{

	public:
			MateriaSource();
			MateriaSource(MateriaSource const &obj);
			~MateriaSource(void);

			MateriaSource &	operator=(MateriaSource const &obj);

			void		learnMateria(AMateria * m);
			AMateria *	createMateria(std::string const & type);

		private:
			AMateria*	materia[4];

};
#endif