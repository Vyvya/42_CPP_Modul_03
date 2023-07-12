/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:53:43 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/12 23:44:30 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

//Default constructor
ScavTrap::ScavTrap() : ClapTrap() {

	std::cout << "ScavTrap " << this->_name << " cloned" << std::endl << std::endl;
}

//Name constructor
ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {

	std::cout << "ScavTrap " << this->_name << " cloned" << std::endl;
}

//Copy constructor
ScavTrap::ScavTrap( const ScavTrap &other) : ClapTrap( other._name ) {

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "Copy constructor on clone ScavTrap" << this->_name << " called" << std::endl;
}

//Destructor
//reverse order of construction: first in, last out
ScavTrap::~ScavTrap() {

	std::cout << "ScavTrap " << this->_name << " eliminated" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &other ) {
	//assignment operator checks if the current object is not the same
	if( this != &other ) {

		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}

	std::cout << "Copy assignement operator on clone ScavTrap " << this->_name << "called" << std::endl;
	return *this;
}

std::string ScavTrap::getName() {

	return this->_name;
}

void ScavTrap::setName( std::string name ) {

	this->_name = name;
}

void ScavTrap::attack(const std::string &target) {

	if( this->hasHitPoints() && this->hasEnergyPoints() ) {

		return;

	} else {

		std::cout << "Clone ScavTrap " << _name << " attacks " << target;
		std::cout << " causing " << this->_attackDamage << " points of damage and loosing 1 energy point" << std::endl;
		
		this->_energyPoints--;
		std::cout << "Clone ScavTrap " << _name << " has now " << this->_energyPoints << " energy points" << std::endl;
		
	}
}

void ScavTrap::takeDamage(unsigned int amount) {

	if( (int)amount < 0 ) {

		std::cout << "Skipping: amount has to be positive int" << std::endl;
		return;
	}
	
	std::cout << "Clone ScavTrap " << _name << " takes damage of "  << amount << " points of damage" << std::endl;
	
	if (this->hasHitPoints() && this->hasEnergyPoints()) {
		
		return;
		
	} else if ( this->_hitPoints <= (int)amount ) {
		
		this->_hitPoints = 0;
		std::cout << "Clone ScavTrap " << _name << " has now " << this->_hitPoints << " hit points!" << std::endl;
		std::cout << "Clone ScavTrap " << _name << " is dead" << std::endl;
		// return;
		return;
	}	
	
	this->_hitPoints -= amount;
	std::cout << "Clone ScavTrap " << _name << " has now " << this->_hitPoints << " hit points" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {

	if( amount < 0 ) {

		std::cout << "Skipping: amount has to be positive int" << std::endl;
		return;
		
	} else if( (this->hasHitPoints()) || (this->hasEnergyPoints()) ) {

		std::cout << "Clone ScavTrap " << _name << " has no life left and cannot be repaired" << std::endl;
		return;

	} else {

		this->_hitPoints += (int)amount;
		std::cout << "Clone ScavTrap " << _name << " being repaired with " << amount << " hit points" << std::endl;
		
		this->_energyPoints--;
		std::cout << "Clone ScavTrap " << _name << " has now " << this->_hitPoints;
		std::cout << " hit points, but lost 1 energy point" << std::endl;
		std::cout << "Clone ScavTrap " << _name << " has now " << this->_energyPoints << " energy points" << std::endl;
		
	}
}

void ScavTrap::guardGate() {

	if( (this->hasHitPoints()) || (this->hasEnergyPoints()) ) {

		std::cout << "Clone ScavTrap " << _name << " has no life left and cannot be repaired" << std::endl;
		return;

	} else {
		
		std::cout << "\033[38;5;118m" << "Clone ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
		std::cout << "\033[0m";
	}
}

bool ScavTrap::hasHitPoints() const {

	if( this->_hitPoints <= 0) {

		std::cout << "Clone ScavTrap " << this->_name << " has no hitPoints left" << std::endl;
		return 1;
	}
	return 0;
}

bool ScavTrap::hasEnergyPoints() const {

	if( this->_energyPoints <= 0) {

		std::cout << "Clone ScavTrap " << this->_name << " has no energyPoints left" << std::endl;
		return 1;
	}
	return 0;
}

void ScavTrap::printInfo( void ) const {

	std::cout << "\033[38;5;141m" << "Clone ScavTrap " << _name << " ** hitPoints: " << _hitPoints << " ** energyPoints: " << _energyPoints;
	std::cout << " ** attackDamage: " << _attackDamage << std::endl;
	std::cout << "\033[0m";
}
