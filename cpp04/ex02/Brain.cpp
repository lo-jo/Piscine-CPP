#include "Brain.hpp"

/** CONSTRUCTORS **/
Brain::Brain(){
	std::cout << GREEN << WBG << "🧠  BRAIN 🧠" << RESET << GREEN << " Constructor called" << RESET << std::endl;
}


Brain::Brain (Brain const& obj){
	std::cout << GREEN << WBG << "🧠  BRAIN 🧠" << RESET << GREEN << " Copy Constructor called"<< RESET << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain &obj){
	if (this != &obj){
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return *this;
}
/** DESTRUCTOR **/
Brain::~Brain(){
	std::cout << GREEN << WBG << "🧠  BRAIN 🧠" << RESET << GREEN << " Destroyed" << RESET << std::endl;
}

/** METHODS **/
std::string Brain::getIdeas(int idx) const {
	if (idx < 0 || idx > 100){
		return ("Invalid Idea");
	}
    return (this->ideas[idx]);
}

void Brain::setIdeas(int idx, std::string const &idea){
	if (idx < 0 || idx > 100){
		std::cout << "Invalid idx" << std::endl;
		return;
	}
	this->ideas[idx] = idea;

}