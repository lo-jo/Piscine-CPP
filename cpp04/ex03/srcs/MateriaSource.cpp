#include "../includes/MateriaSource.hpp"
#include "../includes/AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << BLUE << WBG << "MateriaSource default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	std::cout << BLUE << WBG << "MateriaSource copy constructor called" << RESET<< std::endl;
	for (int i = 0; i < 4; i++)
		this->materia[i] = obj.materia[i];
	*this = obj;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &obj)
{
	std::cout << BLUE << WBG << "MateriaSource copy assignment operator called" << RESET << std::endl;
	for (int i = 0; i < 4; i++){
		if (obj.materia[i])
			this->materia[i] = obj.materia[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << BLUE << WBG << "MateriaSource destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++){
		if (this->materia[i]!= NULL){
			delete this->materia[i];
			this->materia[i] = NULL;
		}	
	}

}

void MateriaSource::learnMateria(AMateria *m)
{
	for(int i = 0 ; i < 4 ; i++ ){
		if (!this->materia[i]){
			this->materia[i] = m;
			break;
		}
	if (i == 3){
		std::cout << "Too little room available to learn new materia... deleting...." << std::endl;
		delete m;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] && this->materia[i]->getType() == type){
			std::cout << "... 🧪 creating " << this->materia[i]->getType() << " materia...." << std::endl;
			return this->materia[i]->clone();

		}
	}
	std::cout << "Materia type \"" << type << "\" not found." << std::endl;
	return 0; // Retourne 0 si le type est inconnu
}
