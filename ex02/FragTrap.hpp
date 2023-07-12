/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:53:47 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/12 23:28:45 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>
#include <string>

// Forward declaration of the ClapTrap class
class ClapTrap;

class FragTrap: public ClapTrap {

	public:

		FragTrap();
		FragTrap( std::string name );
		FragTrap( const FragTrap &other);
		
		~FragTrap();
		
		FragTrap &operator=( const FragTrap &other );

		std::string getName();
		void setName( std::string name );
		
		void highFivesGuys();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		void printInfo( void ) const;
		bool hasHitPoints() const;
		bool hasEnergyPoints() const;
};

#endif
