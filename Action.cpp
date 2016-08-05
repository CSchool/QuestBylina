#include "Action.h"

const Action *findAction(const std::string &name)
{
	static const Action *actions[] = {actionGo, actionTake, actionInventory, 
		actionMap, actionTalk, actionSmoke, actionGive, actionSay, actionUse, actionHelp, actionLook, 0};

	const Action **act = actions;
	while (*act)
	{
		const char * const * actions = (*act)->getNames() ;
		while (*actions)
			if (*actions++ == name)
				return *act ;
		++act;
	}
		/*
	*/
	return NULL ;
}