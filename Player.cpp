#include <iostream>

#include "Player.h"


Player player;


Location *Player::getLocation()
{
	return currentLocation ;
}

void Player::setLocation(Location *loc)
{
	currentLocation = loc ;

	if (currentLocation) currentLocation -> printDescription() ;
		
}

void Player::takeObject(Object *obj)
{
	addObject(obj);
	if ((obj->getKind() == OKBall)&&(locRoom->getObject(OKTeacher) == NULL)) 
	{
		locRoom->addObject(new HumanTeacher);
	}
	std::cout << "Вы получили предмет '" << obj->getName() << "'!\n"  ;

}
