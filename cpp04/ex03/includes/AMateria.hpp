#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "lib.hpp"
#include "ICharacter.hpp"

class ICharacter;

class AMateria{
	public :
		AMateria();
		AMateria(AMateria const &obj);
		AMateria(std::string const &type);
		virtual ~AMateria();

		// Asignment operator overloader
		AMateria &operator=(AMateria const &obj);

		//METHODS
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected :
		std::string type;
};

#endif