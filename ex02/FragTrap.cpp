/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:53:43 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/12 23:47:33 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

//Default constructor
FragTrap::FragTrap() : ClapTrap() {

	std::cout << "FragTrap " << this->_name << " born" << std::endl << std::endl;
}

//Name constructor
FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {

	std::cout << "FragTrap " << this->_name << " born" << std::endl;
}

//Copy constructor
FragTrap::FragTrap( const FragTrap &other) : ClapTrap( other._name ) {

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "Copy constructor on frère FragTrap" << this->_name << " called" << std::endl;
}

//Destructor
//reverse order of construction: first in, last out
FragTrap::~FragTrap() {

	std::cout << "FragTrap " << this->_name << " died" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap &other ) {
	//assignment operator checks if the current object is not the same
	if( this != &other ) {

		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}

	std::cout << "Copy assignement operator on frère FragTrap " << this->_name << "called" << std::endl;
	return *this;
}

std::string FragTrap::getName() {

	return this->_name;
}

void FragTrap::setName( std::string name ) {

	this->_name = name;
}

void FragTrap::attack(const std::string &target) {

	if( this->hasHitPoints() && this->hasEnergyPoints() ) {

		return;

	} else {

		std::cout << "frère FragTrap " << _name << " attacks " << target;
		std::cout << " causing " << this->_attackDamage << " points of damage and loosing 1 energy point" << std::endl;
		
		this->_energyPoints--;
		std::cout << "frère FragTrap " << _name << " has now " << this->_energyPoints << " energy points" << std::endl;
		
	}
}

void FragTrap::takeDamage(unsigned int amount) {

	if( (int)amount < 0 ) {

		std::cout << "Skipping: amount has to be positive int" << std::endl;
		return;
	}
	
	std::cout << "frère FragTrap " << _name << " takes damage of "  << amount << " points of damage" << std::endl;
	
	if (this->hasHitPoints() && this->hasEnergyPoints()) {
		
		return;
		
	} else if ( this->_hitPoints <= (int)amount ) {
		
		this->_hitPoints = 0;
		std::cout << "frère FragTrap " << _name << " has now " << this->_hitPoints << " hit points!" << std::endl;
		std::cout << "frère FragTrap " << _name << " is dead" << std::endl;
		// return;
		return;
	}	
	
	this->_hitPoints -= amount;
	std::cout << "frère FragTrap " << _name << " has now " << this->_hitPoints << " hit points" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {

	if( amount < 0 ) {

		std::cout << "Skipping: amount has to be positive int" << std::endl;
		return;
		
	} else if( (this->hasHitPoints()) || (this->hasEnergyPoints()) ) {

		std::cout << "frère FragTrap " << _name << " has no life left and cannot be repaired" << std::endl;
		return;

	} else {

		this->_hitPoints += (int)amount;
		std::cout << "frère FragTrap " << _name << " being repaired with " << amount << " hit points" << std::endl;
		
		this->_energyPoints--;
		std::cout << "frère FragTrap " << _name << " has now " << this->_hitPoints;
		std::cout << " hit points, but lost 1 energy point" << std::endl;
		std::cout << "frère FragTrap " << _name << " has now " << this->_energyPoints << " energy points" << std::endl;
		
	}
}

void FragTrap::highFivesGuys() {

	std::cout << "\033[38;5;208m" << "Frère FragTrap " << _name << ": Heeyyyyyy! Give me high five 🖐️" << std::endl;
	std::cout << "\033[0m";
}

bool FragTrap::hasHitPoints() const {

	if( this->_hitPoints <= 0) {

		std::cout << "frère FragTrap " << this->_name << " has no hitPoints left" << std::endl;
		return 1;
	}
	return 0;
}

bool FragTrap::hasEnergyPoints() const {

	if( this->_energyPoints <= 0) {

		std::cout << "frère FragTrap " << this->_name << " has no energyPoints left" << std::endl;
		return 1;
	}
	return 0;
}

void FragTrap::printInfo( void ) const {

	std::cout << "\033[38;5;141m" << "frère FragTrap " << _name << " ** hitPoints: " << _hitPoints << " ** energyPoints: " << _energyPoints;
	std::cout << " ** attackDamage: " << _attackDamage << std::endl;
	std::cout << "\033[0m";
}
