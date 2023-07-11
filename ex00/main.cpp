#include "ClapTrap.hpp"

int main() {

	ClapTrap ClapTrap1( "George" );
	ClapTrap ClapTrap2( "Blue" );

	ClapTrap1.attack( ClapTrap2.getName());
	ClapTrap2.takeDamage( 10 );
	ClapTrap2.beRepaired( 3 );
	ClapTrap1.attack( ClapTrap2.getName());
	ClapTrap2.takeDamage( 10 );

	ClapTrap2.attack( ClapTrap1.getName());
	ClapTrap1.takeDamage( 5 );
	ClapTrap1.beRepaired( 3 );

	return 0;
}
