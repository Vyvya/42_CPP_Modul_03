#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

	private:

		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:

		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &other);
		~ClapTrap();
		ClapTrap &operator=( const ClapTrap &other );

		std::string getName();
		void setName( std::string name );

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void print( std::string const &str );
};

#endif