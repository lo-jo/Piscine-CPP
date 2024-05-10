#include "Harl.hpp"

int main(){
	Harl Harl, Harly;
	std::cout << MAG << "Welcome to our first angry Harl." << RESET << std::endl;
	Harl.complain("DEBUG");
	Harl.complain("INFO");
	Harl.complain("WARNING");
	Harl.complain("ERROR");

	
	std::cout << MAG << "Welcome to our second VERY angry Harl." << RESET << std::endl;
	Harly.complain("WARNING");
	Harly.complain("WARNING");
	Harly.complain("ERROR");
	Harly.complain("ERROR");
	
	return (0);
}