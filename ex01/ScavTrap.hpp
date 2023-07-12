/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:53:47 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/12 21:49:58 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>
#include <string>

// Forward declaration of the ClapTrap class
class ClapTrap;

class ScavTrap: public ClapTrap {

	public:

		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &other);
		
		~ScavTrap();
		
		ScavTrap &operator=( const ScavTrap &other );

		std::string getName();
		void setName( std::string name );
		
		void guardGate();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		void printInfo( void ) const;
		bool hasHitPoints() const;
		bool hasEnergyPoints() const;
};

#endif
