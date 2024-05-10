#include "includes/lib.hpp"
#include "includes/Character.hpp"
#include "includes/AMateria.hpp"
#include "includes/Cure.hpp"
#include "includes/Ice.hpp"
#include "includes/ICharacter.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/MateriaSource.hpp"


int main()
{
	std::cout << GREEN << "*********** BASIC TESTS ****************" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << std::endl << GREEN << "*********** ADDITIONAL TESTS ****************" << RESET << std::endl;
	std::cout << GREEN << "Let's create 2 characters : Bobby and Robert" << RESET << std::endl;
	Character* bobby = new Character("Bobby");
	Character* robert = new Character("Robert");
	std::cout<< std::endl << GREEN << "In preparation of Bobby's equipment, let's create some materia" << RESET << std::endl;
	AMateria *materia1 = new Ice();
	AMateria *materia2 = new Ice();
	AMateria *materia3 = new Ice();

	std::cout<< std::endl << GREEN << "Let's try overloading bobbys inventory capacity of 4 materia by first creating in total 6 materia" << RESET << std::endl;
	AMateria *materia4 = new Cure();
	AMateria *materia5 = new Cure();
	AMateria *materia6 = new Cure();

	std::cout<< std::endl << GREEN << "Now Let's equip Bobby of three Ice Materia we just created and 3 extra cure" << RESET << std::endl;
	bobby->equip(materia1);
	bobby->equip(materia2);
	bobby->equip(materia3);

	bobby->equip(materia4);
	bobby->equip(materia5);
	bobby->equip(materia6);
	std::cout<< std::endl << GREEN << "He could not carry the 5th and 6th materia so lets delete them now" << RESET << std::endl;
	//delete(materia5);
	delete(materia6);

	std::cout<< std::endl << GREEN << "Now let's make Bobby use the Ice materia located on the 0th position of his inventory" << RESET << std::endl;
	bobby->use(0, *robert);
	std::cout << GREEN << "Let's make Bobby use some materia that doesnt exist" << RESET << std::endl;
	bobby->use(4, *robert);

	std::cout<< std::endl << GREEN << "DEEP COPY TEST" << RESET << std::endl;
	
	std::cout<< std::endl << GREEN << "equipping robert with cure then copying him" << RESET << std::endl;
	robert->equip(materia5);
	
	Character *robertClone = new Character(*robert);
	std::cout<< std::endl << GREEN << "making the copy use the cure on robert" << RESET << std::endl;
	robertClone->use(0, *robert);
	


	std::cout<< std::endl << GREEN << "Ice is not fun for Bobby, he wants to get rid of it. Let's unequip him" << RESET << std::endl;
	bobby->unequip(0);
	bobby->unequip(1);
	bobby->unequip(2);

	std::cout<< std::endl << GREEN << "Now we have to clean up the floor after bobby..." << RESET << std::endl;
	delete (materia1);
	delete (materia2);
	delete (materia3);
	
	std::cout << std::endl << GREEN << "Character deletion" << RESET << std::endl;

	delete (robert);
	delete bobby;
	delete robertClone;


	std::cout << std::endl << GREEN << "*********** MATERIA SRC ADDITIONAL TESTS ****************" << RESET << std::endl;
	std::cout << std::endl << GREEN << "Testing materia creation of unexisting type" << RESET << std::endl;
	MateriaSource *test= new MateriaSource();
	test->createMateria("bullshit");
	delete(test);
	std::cout << std::endl << GREEN << "Too  much materia in materia source" << RESET << std::endl;
	MateriaSource *source= new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Ice());
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->learnMateria(new Cure());

	std::cout << std::endl << GREEN << "Saving materia to delete clone" << RESET << std::endl;
	std::cout << std::endl << GREEN << "No need to delete failed clone" << RESET << std::endl;
	AMateria* temp = source->createMateria("bs");
	//delete temp;
	std::cout << std::endl << GREEN << "New clone will need 2 b deleted" << RESET << std::endl;
	temp = source->createMateria("cure");
	delete(temp);
	std::cout << std::endl << GREEN << "deleting entire source and its materia" << RESET << std::endl;
	delete(source);



return 0;
}

// A TESTER
/*
MATERIA SOURCE
> emplacements materia
> unexisting materia
> trop de materia
> test deep copy (print la liste de materia apprise)

materia
AMateria * QUIEXISTEPAS = new QUIEXISTEPAS();
emplacements materia
trop dequipement

> equiper character perso->equip(arme);
> unequiper charachter unequip(emplacement);


*/