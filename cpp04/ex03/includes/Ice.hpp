#ifndef ICE_HPP
#define ICE_HPP

#include "lib.hpp"
#include "AMateria.hpp"

class Ice : public AMateria{
	public:
		Ice();
		Ice(Ice const &obj);
		~Ice();

		Ice &operator=(Ice const &obj);

		AMateria* 	clone() const;
		void		use(ICharacter &target);
};

#endif