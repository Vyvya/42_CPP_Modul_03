/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:53:10 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/12 17:34:51 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

	protected:

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

		void printInfo( void ) const;
		bool hasHitPoints() const;
		bool hasEnergyPoints() const;
};

#endif
