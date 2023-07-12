/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:53:02 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/12 23:07:52 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Default constructor
ClapTrap::ClapTrap() : _name("noName"), _hitPoints(100), _energyPoints(50), _attackDamage(20) {

	std::cout << "ClapTrap " << this->_name << " created" << std::endl << std::endl;
}

//Name constructor
ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)  {

	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

//Destructor
ClapTrap::~ClapTrap() {

	std::cout << "ClapTrap " << this->_name << " destoyed" << std::endl;
}

//Copy constructor
ClapTrap::ClapTrap( const ClapTrap &other) {

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &other ) {

	if( this != &other ) {

		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
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

	if( this->hasHitPoints() && this->hasEnergyPoints() ) {

		return;

	} else {

		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << " causing " << this->_attackDamage << " points of damage and loosing 1 energy point" << std::endl;
		
		this->_energyPoints--;
		std::cout << "ClapTrap " << _name << " has now " << this->_energyPoints << " energy points" << std::endl;
		
	}
}

void ClapTrap::takeDamage(unsigned int amount) {

	if( (int)amount < 0 ) {

		std::cout << "Skipping: amount has to be positive int" << std::endl;
		return;
	}
	
	std::cout << "ClapTrap " << _name << " takes damage of "  << amount << " points of damage" << std::endl;
	
	if (this->hasHitPoints() && this->hasEnergyPoints()) {
		
		return;
		
	}else if( this->_hitPoints <= (int)amount ) {
		
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " has now " << this->_hitPoints << " hit points!" << std::endl;
		std::cout << "ClapTrap " << _name << " is dead" << std::endl;
		// return;
		return;
	}	
	
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " has now " << this->_hitPoints << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if( amount < 0 ) {

		std::cout << "Skipping: amount has to be positive int" << std::endl;
		return;
		
	} else if( (this->hasHitPoints()) || (this->hasEnergyPoints()) ) {

		std::cout << "ClapTrap " << _name << " has no life left and cannot be repaired" << std::endl;
		return;

	} else {

		this->_hitPoints += (int)amount;
		std::cout << "ClapTrap " << _name << " being repaired with " << amount << " hit points" << std::endl;
		
		this->_energyPoints--;
		std::cout << "ClapTrap " << _name << " has now " << this->_hitPoints;
		std::cout << " hit points, but lost 1 energy point" << std::endl;
		std::cout << "ClapTrap " << _name << " has now " << this->_energyPoints << " energy points" << std::endl;
		
	}
}

bool ClapTrap::hasHitPoints() const {

	if( this->_hitPoints <= 0) {

		std::cout << "ClapTrap " << this->_name << " has no hitPoints left" << std::endl;
		return 1;
	}
	return 0;
}

bool ClapTrap::hasEnergyPoints() const {

	if( this->_energyPoints <= 0) {

		std::cout << "ClapTrap " << this->_name << " has no energyPoints left" << std::endl;
		return 1;
	}
	return 0;
}

void ClapTrap::printInfo( void ) const {

	std::cout << "\033[38;5;141m" << "ClapTrap " << _name << " ** hitPoints: " << _hitPoints << " ** energyPoints: " << _energyPoints;
	std::cout << " ** attackDamage: " << _attackDamage << std::endl;
	std::cout << "\033[0m";
}
