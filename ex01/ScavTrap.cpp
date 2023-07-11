#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _name("noName"), _hitPoints(100), _energyPoints(50), _attackDamage(20) {

	std::cout << "ScavTrap " << this->_name << " created" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)  {

	std::cout << "ScavTrap " << this->_name << " created" << std::endl;
}

ScavTrap::~ScavTrap() {

	std::cout << "ScavTrap " << this->_name << " destoyed" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other) {

	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &other ) {

	if( this != &other ) {

		this->_name = this->getName();
	}

	std::cout << "Copy assignement operator called" << std::endl;
	return *this;
}

std::string ScavTrap::getName() {

	return this->_name;
}

void ScavTrap::setName( std::string name ) {

	this->_name = name;
}

void ScavTrap::attack(const std::string &target) {

	if( this->_hitPoints > 0 && this->_energyPoints > 0 ) {

		this->_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout << " causing " << this->_attackDamage << " points of damage!" << std::endl;

		std::cout << "ScavTrap " << _name << " has now " << this->_energyPoints << " energy points!" << std::endl;

	} else {

		std::cout << "ScavTrap " << _name << " has no energy left and cannot attack" << std::endl;
		return;
	}
}

void ScavTrap::takeDamage(unsigned int amount) {

	// std::cout << "ScavTrap " << _name << " has " << this->_hitPoints << " hit points!" << std::endl;

	this->_hitPoints -= amount;

	std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	std::cout << "ScavTrap " << _name << " has now " << this->_hitPoints << " hit points!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {

	this->_hitPoints += amount;
	std::cout << "ScavTrap " << _name << " being repaired";
	std::cout << " with " << amount << " hit points!" << std::endl;

	if( _energyPoints > 0 ) {

		this->_energyPoints--;
		std::cout << "ScavTrap " << _name << " has now " << this->_hitPoints << " hit points!" << std::endl;

		std::cout << "ScavTrap " << _name << " lost 1 energy point and has now " << this->_energyPoints << " energy points!" << std::endl;

	} else {

		std::cout << "ScavTrap " << _name << " has no energy left " << std::endl;
		return;
	}
}

void ScavTrap::guardGate() {

	std::cout << "ScavTrap " << _name << " is a guard gate." << std::endl;
}
