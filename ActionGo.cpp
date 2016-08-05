#include "Action.h"
#include "Player.h"
#include <iostream>
class ActionGo : public Action
{
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const 
	{
		Location *curLocation = player.getLocation() ;
		Direction dir = DirUnknown ;
		if (parameter1 == "север") dir = DirNorth ;	
		else if (parameter1 == "юг") dir = DirSouth ;
		else if (parameter1 == "восток") dir = DirEast ;
		else if (parameter1 == "запад") dir = DirWest ;
		curLocation = curLocation -> getDirection(dir) ;
		if (curLocation == NULL) std::cout << "Вы не можете пройти в указанном направлении!\n" ;
		else player.setLocation(curLocation) ;
	}
	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"идти", "иди", "дуй", "шагать", 0};
		return names;
	}
};

static ActionGo action;

const Action *actionGo = &action;