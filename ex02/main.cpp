/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:53:39 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/12 23:48:39 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	ClapTrap clapTrap1( "George" );
	ScavTrap scavTrap1( "Robot" );
	FragTrap fragTrap1( "Boi" );

	clapTrap1.printInfo();
	scavTrap1.printInfo();
	fragTrap1.printInfo();
	scavTrap1.guardGate();
	fragTrap1.highFivesGuys();
	clapTrap1.attack( scavTrap1.getName() );
	clapTrap1.takeDamage(5);
	fragTrap1.highFivesGuys();
	scavTrap1.attack( clapTrap1.getName() );
	scavTrap1.takeDamage(30);
	fragTrap1.highFivesGuys();
	clapTrap1.printInfo();
	scavTrap1.printInfo();
	fragTrap1.printInfo();

	return 0;
}
