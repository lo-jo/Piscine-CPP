#include "Zombie.hpp"

int	main(){
	std::cout << BOLD << YEL << "STACK" << RESET << 
	std::endl << "Zombie creation through constructor means long lifespan" << std::endl;
	Zombie Bob = Zombie("Bob");
	Bob.announce();

	std::cout << BOLD << YEL << "STACK" << RESET << 
	std::endl << "Zombie through randomChump() (will die sooner)" << std::endl;
	randomChump("Rob");

	std::cout << BOLD << YEL << "HEAP" << RESET << 
	std::endl << "Zombie creation through newZombie()" << 
	std::endl << "Uses dynamic memory allocation and will need to be deleted at the end of the function" << std::endl;
	Zombie* Bobby = newZombie("Bobby");
	Bobby->announce();
	delete Bobby;
	return 0 ;
}