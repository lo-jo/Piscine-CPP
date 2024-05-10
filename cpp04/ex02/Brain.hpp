#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "lib.hpp"

class Brain{
	public:
    Brain();
	Brain(Brain const& obj);
    ~Brain();
    Brain& operator=(Brain const& obj);

    std::string getIdeas(int idx) const;
	void setIdeas(int idx, std::string const &idea);

	private:
	std::string ideas[100];
};

#endif