#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("noName"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)  {

	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::~ClapTrap() {

	std::cout << "ClapTrap " << this->_name << " destoyed" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other) {

	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &other ) {

	if( this != &other ) {

		this->_name = this->getName();
	}

	std::cout << "Copy assignement operator called" << std::endl;
	return *this;
}

std::string ClapTrap::getName() {

	return this->_name;
}

void ClapTrap::setName( std::string name ) {

	this->_name = name;
}

void ClapTrap::attack(const std::string &target) {

	if( this->_hitPoints > 0 && this->_energyPoints > 0 ) {

		this->_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << " causing " << this->_attackDamage << " points of damage!" << std::endl;

		std::cout << "ClapTrap " << _name << " has now " << this->_energyPoints << " energy points!" << std::endl;

	} else {

		std::cout << "ClapTrap " << _name << " has no energy left and cannot attack" << std::endl;
		return;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {

	// std::cout << "ClapTrap " << _name << " has " << this->_hitPoints << " hit points!" << std::endl;

	this->_hitPoints -= amount;

	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << _name << " has now " << this->_hitPoints << " hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

	this->_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " being repaired";
	std::cout << " with " << amount << " hit points!" << std::endl;

	if( _energyPoints > 0 ) {

		this->_energyPoints--;
		std::cout << "ClapTrap " << _name << " has now " << this->_hitPoints << " hit points!" << std::endl;

		std::cout << "ClapTrap " << _name << " lost 1 energy point and has now " << this->_energyPoints << " energy points!" << std::endl;

	} else {

		std::cout << "ClapTrap " << _name << " has no energy left " << std::endl;
		return;
	}
}
