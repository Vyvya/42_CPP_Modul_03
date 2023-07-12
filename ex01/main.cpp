/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:53:39 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/12 23:22:45 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

	ClapTrap clapTrap1( "George" );
	ScavTrap scavTrap1( "Robot" );

	clapTrap1.printInfo();
	scavTrap1.printInfo();
	scavTrap1.guardGate();
	clapTrap1.attack( scavTrap1.getName() );
	clapTrap1.takeDamage(5);
	scavTrap1.attack( clapTrap1.getName() );
	scavTrap1.takeDamage(10);
	clapTrap1.printInfo();
	scavTrap1.printInfo();

	return 0;
}
