#include "Action.h"
#include "Player.h"
#include <iostream>

class ActionLook : public Action
{
	
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const
	{
		Location *temp_name = player.getLocation();
		temp_name->printDescription();
	}
	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"осмотреться", "осмотреть", "локация", "место", 0};
		return names;
	}
	
};

static ActionLook action;

const Action *actionLook = &action;