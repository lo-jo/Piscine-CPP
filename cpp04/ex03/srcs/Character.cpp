#include "../includes/Character.hpp"

Character::Character() : name("Generic"){
	std::cout << BLK << PBG << " CHARACTER " << RESET << " Constructor called" << std::endl;
	std::cout << BLK << PBG << "           " << RESET << " Welcome " << this->getName() << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const &obj){
	std::cout << BLK << PBG << "  CHARACTER  " << RESET << " COpy Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = obj;
}

Character::Character(std::string const &name) :
	name(name){
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << BLK << PBG << "   CHARACTER  " << RESET << " adhoc Constructor called" << std::endl;
	std::cout << BLK << PBG << "      👤      " << RESET << " Welcome " << MAG << this->getName() << RESET << std::endl;
}

Character &Character::operator=(Character const &obj){
	std::cout << BLK << PBG << "  CHARACTER  " << RESET << " assignment constructor " << std::endl;
	this->name = obj.name;

	for (int i = 0; i < 4; i++){
		if (obj.inventory[i] != NULL){
			AMateria *tmp = obj.inventory[i]->clone();
			delete this->inventory[i];
			this->inventory[i] = tmp;
		}
	}
	return *this;
}

void Character::deleteMat(){
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL){
			delete (this->inventory[i]);
			this->inventory[i] = NULL;
		}
	}

	return;
}
Character::~Character(){
	std::cout << BLK << PBG << "   CHARACTER  " << RESET << this->getName() << " destructor called" << std::endl;
	this->deleteMat();
}
//ACCESSORS
std::string	const &Character::getName() const{
	return this->name;
}

// METHODS
void Character::equip(AMateria* m){
	if (m){
		for (int i = 0; i < 4; i++){
			if (this->inventory[i] == NULL){
				this->inventory[i] = m;
				std::cout << "++ " << this->getName() << " got equipped with " << BLUE << m->getType() << RESET << std::endl;
				break;
			}
		}
	}
}

void Character::unequip(int idx){
	if (this->inventory[idx] != NULL){
		std::cout << "-- "<< this->getName() << " left their " << this->inventory[idx]->getType() << " on the floor" << std::endl;
		
		this->inventory[idx] = NULL;
	}
}

/*
a fonction membre use(int, ICharacter&) utilisera la Materia de l’emplacement[idx],
et passera la cible en paramètre à la fonction AMateria::use*/
void Character::use(int idx, ICharacter& target){
	if (this->inventory[idx] != NULL && (idx >= 0 && idx < 4)){
		//std::cout << this->name << " used " << this->inventory[idx]->getType() << " materia on " << target.getName() << std::endl;
		this->inventory[idx]->use(target);
	}
	else{
		std::cout << "Materia not found" << std::endl;
	}
}
