#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "lib.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter{
	public :
	Character();
	Character(Character const &obj);
	Character(std::string const &name);
	~Character();

	Character &operator=(Character const &obj);

	//ACCESSORS
	std::string	const &getName() const;

	// METHODS
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	private :
	AMateria	*inventory[4];
	std::string	name;
	void	deleteMat();
};

#endif