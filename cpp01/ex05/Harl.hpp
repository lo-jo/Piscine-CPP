#ifndef HARL_HPP
#define HARL_HPP


#include <iostream> 
#include <string>

#define DEBUG "I love having extra bacon for my 7XL-double-cheese-burger. I really do !"
#define INFO "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !"
#define WARNING "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
#define ERROR "This is unacceptable ! I want to speak to the manager now."

// ANSI COLORS
#define WBG "\x1B[47m"
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define MAG "\x1B[35m"
#define YEL "\x1B[33m"
#define RED "\x1B[31m"

class	Harl{
	public :
		Harl();
		~Harl();
		void complain( std::string level );

	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif