/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:53:19 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/11 18:37:20 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

	ClapTrap ClapTrap1( "George" );
	ClapTrap ClapTrap2( "Blue" );

	ClapTrap1.printInfo();
	ClapTrap2.printInfo();
	
	if ( ClapTrap1.hasHitPoints() || ClapTrap1.hasEnergyPoints() ) {

		std::cout << "ClapTrap " << ClapTrap1.getName() << " has no life left and cannot attack" << std::endl;
		return 0;
	}
	
	ClapTrap1.attack( ClapTrap2.getName());
	ClapTrap2.takeDamage( 3 );
	ClapTrap2.beRepaired( 0 );
	ClapTrap2.takeDamage( 4 );

	ClapTrap1.printInfo();
	ClapTrap2.printInfo();
	
	if ( ClapTrap2.hasHitPoints() || ClapTrap2.hasEnergyPoints() ) {

		std::cout << "ClapTrap " << ClapTrap2.getName() << " has no life left and cannot attack" << std::endl;
		return 0;
	}
		
	ClapTrap2.attack( ClapTrap1.getName());
	ClapTrap1.takeDamage( 5 );
	ClapTrap1.beRepaired( 3 );

	ClapTrap1.printInfo();
	ClapTrap2.printInfo();
	
	return 0;
}
